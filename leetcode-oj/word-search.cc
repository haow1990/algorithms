#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool visit(const vector<vector<char> > &board, vector<vector<bool> > &unvisited, const string &word, size_t iw, size_t m, size_t n) {
        size_t W = board[0].size();
        size_t H = board.size();
        if (unvisited[m][n] && board[m][n] == word[iw]) {
            if (iw + 1 == word.size())
                return true;
            unvisited[m][n] = false;
            if (m > 0 && visit(board, unvisited, word, iw+1, m-1, n)) {
                return true;
            }
            if (n > 0 && visit(board, unvisited, word, iw+1, m, n-1)) {
                return true;
            }
            if (m+1 < H &&
                    visit(board, unvisited, word, iw+1, m+1, n)) {
                return true;
            }
            if (n+1 < W &&
                    visit(board, unvisited, word, iw+1, m, n+1)) {
                return true;
            }
            unvisited[m][n] = true;
            return false;
        } else {
            return false;
        }
    }
    bool exist(vector<vector<char> > &board, string word) {
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        size_t W = board[0].size();
        size_t H = board.size();
        if (word.size() > W * H)
            return false;
        if (word.empty())
            return true;
        vector<vector<bool> > unvisited(H, vector<bool>(W, true));
        for (size_t m = 0; m < H; ++m) {
            for (size_t n = 0; n < W; ++n) {
                if (visit(board, unvisited, word, 0, m, n))
                    return true;
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
