#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool equal(const string &s1, int i, int j, const string &s2, int k) {
        while (i <= j) {
            if (s1[i++] != s2[k++]) {
                return false;
            }
        }
        return true;
    }
    
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        } else if (s1.empty()) {
            return true;
        }
        // isScramble(s1[i..j], s2[k..j-i+k]) => dp[i][j][k]
        vector<vector<vector<bool> > > dp(s1.size(), vector<vector<bool> >(s1.size(), vector<bool>(s2.size())));
        for (int len = 1; len <= s1.size(); ++len) {
            for (int i = 0; i + len <= s1.size(); ++i) {
                int j = i + len - 1;
                for (int k = 0; k + len <= s2.size(); ++k) {
                    if (equal(s1, i, j, s2, k)) {
                        dp[i][j][k] = true;
                        continue;
                    }
                    dp[i][j][k] = false;
                    for (int left = 1; left < len; ++left) {
                        if ((dp[i][i+left-1][k] && dp[i+left][j][k+left])
                             || (dp[i][i+left-1][k+len-left] && dp[i+left][j][k])) {
                            dp[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][s1.size()-1][0];
    }
};
int main(int argc, char **argv)
{
    string s1(argv[1]);
    string s2(argv[2]);
    Solution s;
    cout << s.isScramble(s1, s2) << endl;
    return 0;
}
