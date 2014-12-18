#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool bfs(vector<vector<char> > &board, string &word, int i, int j, int iw, vector<vector<bool> > &visited) {
        if (iw >= word.size()) {
            return true;
        }
        const int m = board.size();
        const int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if (visited[i][j]) {
            return false;
        }
        if (word[iw] != board[i][j]) {
            return false;
        }
        visited[i][j] = true;
        if (bfs(board, word, i-1, j, iw+1, visited)
            || bfs(board, word, i+1, j, iw+1, visited)
            || bfs(board, word, i, j-1, iw+1, visited)
            || bfs(board, word, i, j+1, iw+1, visited)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty()) {
            return true;
        }
        if (board.empty() || board[0].empty()) {
            return false;
        }
        const int m = board.size();
        const int n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (bfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

};

int main(int argc, char **argv)
{
    vector<vector<char> > board{{'a','b','c','e'}, {'s','f','c','s'},{'a','d','e','e'}};
    //string str("see");
    //string str("abcced");
    string str("abcb");
    Solution s;
    cout << s.exist(board, str) << endl;
    return 0;
}
