#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &result, vector<int> &path, map<int, int>::iterator current, map<int, int>::iterator end) {
        if (current == end) {
            result.push_back(path);
            return;
        }
        int originalSize = path.size();
        auto next = current;
        ++next;
        for (int i = 0; i <= current->second; ++i) {
            dfs(result, path, next, end);
            path.push_back(current->first);
        }
        path.resize(originalSize);
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        map<int, int> nums;
        for (int n : S) {
            ++nums[n];
        }
        vector<vector<int> > result;
        vector<int> path;
        dfs(result, path, nums.begin(), nums.end());
        return result;
    }
};

int main()
{
    vector<int> s{1,2,2};
    Solution sol;
    vector<vector<int> > result = sol.subsetsWithDup(s);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
