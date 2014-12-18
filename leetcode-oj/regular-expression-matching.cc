#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (s == nullptr || p == nullptr) {
            return false;
        }
        const int slen = strlen(s);
        const int plen = strlen(p);
        int minlen = 0;
        bool hasstar = false;
        for (int j = 0; j < plen; ++j) {
            if (p[j] == '*') {
                hasstar = true;
                --minlen;
            } else {
                ++minlen;
            }
        }
        if (slen < minlen || (hasstar == false && slen > minlen)) {
            return false;
        }
        vector<vector<bool> > dp(slen + 1, vector<bool>(plen + 1));
        dp[0][0] = true;
        for (int i = 1; i <= slen; ++i) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= plen; ++j) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            } else {
                dp[0][j] = false;
            }
        }
        for (int i = 1; i <= slen; ++i) {
            for (int j = 1; j <= plen; ++j) {
                if (p[j-1] != '*') {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '.' || p[j-1] == s[i-1]);
                } else {
                    //          no match
                    dp[i][j] = dp[i][j-1] || dp[i][j-2] ||
                               (dp[i-1][j] && (p[j-2] == '.' || p[j-2] == s[i-1]));
                }
            }
        }
        return dp[slen][plen];
    
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isMatch(argv[1], argv[2]) << endl;
    return 0;
}
