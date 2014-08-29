#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<string> > &result, vector<bool> &column,
            vector<bool> &bleft, vector<bool> &bright,
            vector<string> &current, int idx)
    {
        if (idx >= column.size()) {
            result.push_back(current);
            return;
        }
        for (int j = 0; j < column.size(); ++j) {
            if (column[j]
                    || bleft[idx-j+column.size()]
                    || bright[j+idx]) {
                continue;
            }
            column[j] = true;
            bleft[idx-j+column.size()] = true;
            bright[j+idx] = true;
            current[idx][j] = 'Q';

            solve(result, column, bleft, bright, current, idx + 1);

            column[j] = false;
            bleft[idx-j+column.size()] = false;
            bright[j+idx] = false;
            current[idx][j] = '.';
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if (n == 0) {
            return result;
        }
        vector<bool> column(n, false);
        vector<bool> bleft(n * 2, false);
        vector<bool> bright(n * 2, false);
        vector<string> current(n, string(n, '.'));
        solve(result, column, bleft, bright, current, 0);
        return result;
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
