#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &result, vector<int> &path, int idx, int now, int n) {
        if (idx >= path.size()) {
            result.push_back(path);
            return;
        } else if (now > n) {
            return;
        }
        // no add
        dfs(result, path, idx, now + 1, n);
        // add
        path[idx] = now;
        dfs(result, path, idx + 1, now + 1, n);
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if (n < 1 || n < k) {
            return result;
        }
        vector<int> path(k);
        dfs(result, path, 0, 1, n);
        return result;
    }

};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    Solution sol;
    vector<vector<int> > result = sol.combine(n, k);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "--";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
