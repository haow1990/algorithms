#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> path(n, string(n, '.'));
        vector<bool> vertical(n, false);
        vector<bool> slash(n * 2, false);
        vector<bool> backslash(n * 2, false);
        function<void(int)> backtrack = [&](int idx)->void{
            if (idx >= n) {
                res.push_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vertical[j] || slash[idx+j] || backslash[idx-j+n-1]) {
                    continue;
                }
                vertical[j] = true;
                slash[idx+j] = true;
                backslash[idx-j+n-1] = true;
                path[idx][j] = 'Q';
                backtrack(idx + 1);
                path[idx][j] = '.';
                vertical[j] = false;
                slash[idx+j] = false;
                backslash[idx-j+n-1] = false;
            }
        };
        backtrack(0);
        return res;
    }

};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    vector<vector<string> > result = s.solveNQueens(n);
    for (auto &vs : result) {
        for (auto &str : vs) {
            cout << str << endl;
        }
        cout << endl;
    }
    return 0;
}
