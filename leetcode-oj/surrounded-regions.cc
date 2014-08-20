#include <iostream>
#include <vector>
using namespace std;

void traverseRegion(int i, int j, vector<vector<char>> &board)
{
    const int M = board.size();
    const int N = board[0].size();
    board[i][j] = '.';
    if (i > 0 && board[i-1][j] == 'O') traverseRegion(i-1, j, board);
    if (j > 0 && board[i][j-1] == 'O') traverseRegion(i, j-1, board);
    if (i+1 < M && board[i+1][j] == 'O') traverseRegion(i+1, j, board);
    if (j+1 < N && board[i][j+1] == 'O') traverseRegion(i, j+1, board);
}

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3) {
            return;
        }
        if (board[0].size() < 3) {
            return;
        }
        const int M = board.size();
        const int N = board[0].size();
        for (size_t i = 0; i < M; ++i) {
            if (board[i][0] == 'O') traverseRegion(i, 0, board);
            if (board[i][N-1] == 'O') traverseRegion(i, N-1, board);
        }
        for (size_t j = 0; j < N; ++j) {
            if (board[0][j] == 'O') traverseRegion(0, j, board);
            if (board[M-1][j] == 'O') traverseRegion(M-1, j, board);
        }
        char cmap[256];
        cmap['X'] = 'X';
        cmap['O'] = 'X';
        cmap['.'] = 'O';
        for (size_t i = 0; i < M; ++i) {
            for (size_t j = 0; j < N; ++j) {
                board[i][j] = cmap[board[i][j]];
            }
        }
    }
};

int main()
{
    vector<vector<char>> board;
    char O = 'O';
    char X = 'X';
    board.resize(6);    board[0].push_back(O);    board[0].push_back(O);    board[0].push_back(O);    board[0].push_back(O);    board[0].push_back(O);    board[0].push_back(O);    board[1].push_back(O);    board[1].push_back(X);    board[1].push_back(X);    board[1].push_back(X);    board[1].push_back(X);    board[1].push_back(O);    board[2].push_back(O);    board[2].push_back(X);    board[2].push_back(O);    board[2].push_back(O);    board[2].push_back(X);    board[2].push_back(O);    board[3].push_back(O);    board[3].push_back(X);    board[3].push_back(O);    board[3].push_back(O);    board[3].push_back(X);    board[3].push_back(O);    board[4].push_back(O);    board[4].push_back(X);    board[4].push_back(X);    board[4].push_back(X);    board[4].push_back(X);    board[4].push_back(O);    board[5].push_back(O);    board[5].push_back(O);    board[5].push_back(O);    board[5].push_back(O);    board[5].push_back(O);    board[5].push_back(O);
    Solution s;
    s.solve(board);
    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }
	return 0;
}
