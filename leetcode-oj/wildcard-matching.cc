#include <climits>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

struct pattern {
    bool isPlain;
    string str;
    int min;
    int max;
    int got;

    pattern(char cc)
        : isPlain(true), str(1, cc), min(1), got(0)
    {}

    pattern(int minval, int maxval)
        : isPlain(false), str(), min(minval), max(maxval), got(0)
    {}
};

class Solution {
public:
    void compile(const char *p, vector<pattern> &ptn)
    {
        while (*p != '\0') {
            switch (*p) {
            case '*':
                if (ptn.empty() || ptn.back().isPlain) {
                    ptn.push_back(pattern(0, INT_MAX ));
                } else {
                    ptn.back().max = INT_MAX; 
                }
                break;

            case '?':
                if (ptn.empty() || ptn.back().isPlain) {
                    ptn.push_back(pattern(1, 1));
                } else {
                    ptn.back().min += 1;
                    if (ptn.back().max < INT_MAX) {
                        ptn.back().max += 1;
                    }
                }
                break;

            default:
                if (ptn.empty() || ptn.back().isPlain == false) {
                    ptn.push_back(pattern(*p));
                } else {
                    ptn.back().str.push_back(*p);
                }
            }
            
            ++p;
        }
    }

    bool doMatch(const char *s, vector<pattern> &ptn, size_t pos)
    {
        cout << pos << endl;
        pattern &cp = ptn[pos];
        // source string comes to the end
        if (*s == '\0') {
            // no pattern left, got end
            if (pos >= ptn.size()) {
                return true;
            }
            // not last pattern yet
            if (pos + 1 < ptn.size()) {
                return false;
            }
            // last pattern
            return cp.isPlain == false
                && cp.got >= cp.min;
        }

        // pattern comes to the end
        if (pos >= ptn.size()) {
            return false;
        }

        // match current
        if (cp.isPlain) {
            // plain character must exactly match
            size_t istr = 0;
            while (*s && istr < cp.str.size() && *s == cp.str[istr]) {
                ++istr;
                ++s;
            }
            if (istr != cp.str.size()) {
                return false;
            } else {
                return doMatch(s, ptn, pos+1);
            }
        } else {
            // glob, eat min characters first
            while (*s && cp.got < cp.min) {
                ++s;
                ++cp.got;
            }
            // still hungry but source ends
            if (cp.got < cp.min) {
                return false;
            }
            if (pos + 1 == ptn.size()) {
                return strlen(s) + cp.got <= cp.max;
            }
            char expected = ptn[pos+1].str[0];
            while (*s != '\0' && *s != expected) {
                ++s;
            }
            // next pattern must be a plain, so find it first
            do {
                if (doMatch(s, ptn, pos + 1) == true) {
                    return true;
                }
                if (*s == '\0') {
                    break;
                }
                ++s;
                ++cp.got;
            } while (cp.got <= cp.max);
            return false;
        }
    }

    bool isMatch(const char *s, const char *p) {
        vector<pattern> ptn;
        compile(p, ptn);
        return doMatch(s, ptn, 0);
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isMatch(argv[1], argv[2]) << endl;
    return 0;
}
