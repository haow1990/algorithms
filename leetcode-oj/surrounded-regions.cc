#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        const int m = board.size();
        const int n = board[0].size();
        queue<pair<int, int> > q;
        auto push_if = [&](int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
                return;
            }
            board[i][j] = '.';
            q.push(make_pair(i, j));
        };
        for (int i = 0; i < m; ++i) {
            push_if(i, 0);
            push_if(i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            push_if(0, j);
            push_if(m - 1, j);
        }
        while (q.empty() == false) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            push_if(i - 1, j);
            push_if(i + 1, j);
            push_if(i, j - 1);
            push_if(i, j + 1);
        }
        
        char cmap[256];
        cmap['X'] = 'X';
        cmap['O'] = 'X';
        cmap['.'] = 'O';
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
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
