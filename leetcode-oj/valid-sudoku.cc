#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    bool rows[9][9];
    bool cols[9][9];
    bool grid[3][3][9];

    bool isValidSudoku(vector<vector<char> > &board) {
        bzero(rows, sizeof(rows));
        bzero(cols, sizeof(cols));
        bzero(grid, sizeof(grid));
        for (int i =  0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (rows[i][num] || cols[j][num] || grid[i/3][j/3][num]) {
                        return false;
                    }
                    rows[i][num] = true;
                    cols[j][num] = true;
                    grid[i/3][j/3][num] = true;
                }
            }
        }
        return true;
    }
};

int main(int argc, char **argv)
{
    vector<vector<char> > board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    Solution s;
    cout << s.isValidSudoku(board) << endl;
    return 0 ;
}
