#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &result, vector<int> &path, set<int>::iterator current, set<int>::iterator end, int target) {
        if (target == 0) {
            if (path.empty() == false) {
                result.push_back(path);
            }
            return;
        }
        if (current == end || *current > target) {
            return;
        }
        auto next = current;
        ++next;
        // no add me
        dfs(result, path, next, end, target);
        // add me
        path.push_back(*current);
        dfs(result, path, current, end, target - *current);
        path.pop_back();
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        set<int> nums;
        for (int v : candidates) {
            nums.insert(v);
        }
        vector<int> path;
        vector<vector<int> > result;
        dfs(result, path, nums.begin(), nums.end(), target);
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
    vector<vector<int> > result = s.combinationSum(candidates, target);
    for (auto &vec : result) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
