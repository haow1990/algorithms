#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    void doperm(const vector<int> &num, vector<vector<int> > &result, vector<int> &path, int idx, map<int, int> &visited)
    {
        if (idx >= num.size()) {
            result.push_back(path);
            return;
        }
        for (auto iter = visited.begin();
                iter != visited.end(); ++iter) {
            if (iter->second == 0) {
                continue;
            }
            iter->second -= 1;
            path.push_back(iter->first);
            doperm(num, result, path, idx + 1, visited);
            path.pop_back();
            iter->second += 1;
        }
    }

    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() <= 0) {
            return result;
        }
        map<int, int> snum;
        for (int n : num) {
            auto iter = snum.find(n);
            if (iter == snum.end()) {
                snum[n] = 1;
            } else {
                iter->second += 1;
            }
        }
        vector<int> path;
        doperm(num, result, path, 0, snum);
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<int> num;
    for (int i = 1; i < argc; ++i) {
        num.push_back(atoi(argv[i]));
    }
    Solution s;
    vector<vector<int> > result = s.permute(num);

    for (auto &vec : result) {
        for (auto i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}

