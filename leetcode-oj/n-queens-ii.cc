#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int result;
    void solve(vector<bool> &column,
            vector<bool> &bleft, vector<bool> &bright,
            int idx)
    {
        if (idx >= column.size()) {
            ++result;
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

            solve(column, bleft, bright, idx + 1);

            column[j] = false;
            bleft[idx-j+column.size()] = false;
            bright[j+idx] = false;
        }
    }

    int totalNQueens(int n) {
        if (n == 0) {
            return 0;
        }
        result = 0;
        vector<bool> column(n, false);
        vector<bool> bleft(n * 2, false);
        vector<bool> bright(n * 2, false);
        solve(column, bleft, bright, 0);
        return result;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    int result = s.totalNQueens(n);
    cout << result << endl;
    return 0;
}
