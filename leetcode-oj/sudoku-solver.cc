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

    bool solveIt(vector<vector<char> > &board, int idx)
    {
        if (idx >= 81) {
            return true;
        }
        const int i = idx / 9;
        const int j = idx % 9;
        if (board[i][j] != '.') {
            return solveIt(board, idx + 1);
        }
        for (int n = 0; n < 9; ++n) {
            if (rows[i][n] || cols[j][n] || grid[i/3][j/3][n]) {
                continue;
            }
            rows[i][n] = true;
            cols[j][n] = true;
            grid[i/3][j/3][n] = true;
            board[i][j] = '1' + n;
            if (solveIt(board, idx + 1) == true) {
                return true;
            }
            rows[i][n] = false;
            cols[j][n] = false;
            grid[i/3][j/3][n] = false;
        }
        board[i][j] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        bzero(rows, sizeof(rows));
        bzero(cols, sizeof(cols));
        bzero(grid, sizeof(grid));
        for (int i =  0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    grid[i/3][j/3][num] = true;
                }
            }
        }
        solveIt(board, 0);
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
    for (auto &vec : board) {
        for (char c : vec) {
            cout << c << ' ';
        }
        cout << endl;
    }
    cout << endl;
    Solution s;
    s.solveSudoku(board);
    for (auto &vec : board) {
        for (char c : vec) {
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0 ;
}
