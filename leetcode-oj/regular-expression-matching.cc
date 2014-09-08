#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        string str(s);
        string ptn(p);
        int min = 0, max = 0;
        for (size_t j = 0; j < ptn.size(); ++j) {
            if (ptn[j] == '*') {
                max = INT_MAX;
                if (j == 0 || ptn[j-1] == '*') {
                    return false;   // invalid pattern
                }
                --min;
            } else {
                if (max != INT_MAX) {
                    ++max;
                }
                ++min;
            }
        }
        if (str.size() < min || str.size() > max) {
            return false;
        }

        vector<vector<bool> > array(str.size() + 1, vector<bool>(ptn.size() + 1));
        array[0][0] = true;
        for (size_t i = 1; i <= str.size(); ++i) {
            array[i][0] = false;
        }
        for (size_t j = 1; j <= ptn.size(); ++j) {
            if (ptn[j-1] != '*') {
                array[0][j] = false;
            } else {
                array[0][j] = array[0][j-2];
            }
        }

        for (size_t i = 1; i <= str.size(); ++i) {
            for (size_t j = 1; j <= ptn.size(); ++j) {
                if (ptn[j-1] == '*') {
                    array[i][j] = array[i][j-1] || array[i][j-2] ||
                        (array[i-1][j] && (ptn[j-2] == '.' || ptn[j-2] == str[i-1]));
                } else {
                    array[i][j] = array[i-1][j-1] &&
                        (ptn[j-1] == '.' || ptn[j-1] == str[i-1]);
                }
            }
        }
        return array[str.size()][ptn.size()];
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isMatch(argv[1], argv[2]) << endl;
    return 0;
}
