#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void combine(map<int, int> &numbers, map<int, int>::iterator iter,
            vector<vector<int> > &result, vector<int> &path, int sum) {
        if (sum == 0) {
            result.push_back(path);
            return;
        }
        if (iter == numbers.end()) {
            return;
        }
        size_t originalSize = path.size();
        int current = iter->first;
        int count = iter->second;
        auto next = ++iter;
        for (int i = 0; i <= count && i * current <= sum; ++i) {
            int newsum = sum - i * current;
            if (newsum != 0 && newsum < current) {
                break;
            }
            combine(numbers, next, result, path, newsum);
            path.push_back(current);
        }
        path.resize(originalSize);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        map<int, int> numbers;
        for (int n : num) {
            auto iter = numbers.find(n);
            if (iter != numbers.end()) {
                iter->second += 1;
            } else {
                numbers[n] = 1;
            }
        }
        vector<vector<int> > result;
        vector<int> path;
        combine(numbers, numbers.begin(), result, path, target);
        return result;
    }
};

int main(int argc, char **argv)
{
    int target = atoi(argv[1]);
    vector<int> candidates;
    for (int i = 2; i < argc; ++i) {
        candidates.push_back(atoi(argv[i]));
    }

    Solution s;
    vector<vector<int> > result = s.combinationSum2(candidates, target);
    for (auto &vec : result) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
