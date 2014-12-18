#include <climits>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const int slen = strlen(s);
        const int plen = strlen(p);
        int minlen = 0;
        bool star = false;
        for (int j = 0; j < plen; ++j) {
            if (p[j] == '*') {
                star = true;
            } else {
                ++minlen;
            }
        }
        if (slen < minlen || (star == false && slen > minlen)) {
            return false;
        }
        vector<vector<bool> > dp(slen+1, vector<bool>(plen+1));
        dp[0][0] = true;
        for (int i = 1; i <= slen; ++i) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= plen; ++j) {
            dp[0][j] = dp[0][j-1] && p[j-1] == '*';
        }
        for (int i = 1; i <= slen; ++i) {
            for (int j = 1; j <= plen; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
                } else {
                    dp[i][j] = dp[i-1][j-1] && (p[j-1] == '?' || p[j-1] == s[i-1]);
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
