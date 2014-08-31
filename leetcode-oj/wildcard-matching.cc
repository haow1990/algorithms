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
    int minRight;
    int maxRight;

    pattern(char cc)
        : isPlain(true), str(1, cc), min(1), max(1), minRight(1), maxRight(1)
    {}

    pattern(int minval, int maxval)
        : isPlain(false), str(), min(minval), max(maxval), minRight(minval), maxRight(maxval)
    {}
};

enum status {
    NONE,
    YES,
    NO
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
                    ptn.back().min += 1;
                    ptn.back().max += 1;
                }
            }
            
            ++p;
        }

        if (ptn.empty()) {
            return;
        }

        ptn.back().minRight = ptn.back().min;
        ptn.back().maxRight = ptn.back().max;
        for (int i = ptn.size() - 2; i >= 0; --i) {
            ptn[i].minRight = ptn[i].min + ptn[i+1].minRight;
            if (ptn[i].max == INT_MAX || ptn[i+1].maxRight == INT_MAX) {
                ptn[i].maxRight = INT_MAX;
            } else {
                ptn[i].maxRight = ptn[i].max + ptn[i+1].maxRight;
            }
        }
    }

    bool doMatch(const string &str, size_t istr, vector<pattern> &ptn, size_t pos, vector<vector<int> > &array)
    {
        const size_t ai = istr;
        const size_t aj = pos;
        if (array[ai][aj] != NONE) {
            return array[ai][aj] == YES ? true : false;
        }
        pattern &cp = ptn[pos];
        // source string comes to the end
        if (istr == str.size()) {
            // no pattern left, got end
            if (pos >= ptn.size()) {
                array[ai][aj] = YES;
                return true;
            }
            // not last pattern yet
            if (pos + 1 < ptn.size()) {
                array[ai][aj] = NO;
                return false;
            }
            // last pattern
            bool result = cp.isPlain == false && cp.min == 0;
            array[ai][aj] = result ? YES : NO;
            return result;
        }

        // pattern comes to the end
        if (pos >= ptn.size()) {
            array[ai][aj] = NO;
            return false;
        }

        // match current
        if (cp.isPlain) {
            // plain character must exactly match
            size_t ipstr = 0;
            if (str.size() - istr < cp.str.size()) {
                array[ai][aj] = NO;
                return false;
            }
            while (ipstr < cp.str.size() && str[istr] == cp.str[ipstr]) {
                ++ipstr;
                ++istr;
            }
            if (ipstr != cp.str.size()) {
                array[ai][aj] = NO;
                return false;
            } else {
                bool result = doMatch(str, istr, ptn, pos+1, array);
                array[ai][aj] = result ? YES : NO;
                return result;
            }
        } else {
            // glob, eat min characters first
            if (str.size() - istr < cp.minRight) {
                array[ai][aj] = NO;
                return false;
            }
            // last pattern
            if (pos + 1 == ptn.size()) {
                bool result = str.size() - istr <= cp.max;
                array[ai][aj] = result ? YES : NO;
                return result;
            }
            if (str.size() - istr > cp.maxRight) {
                array[ai][aj] = NO;
                return false;
            }
            int start = istr + cp.min;
            if (ptn[pos+1].maxRight != INT_MAX
                    && start < str.size() - ptn[pos+1].maxRight) {
                start = str.size() - ptn[pos+1].maxRight;
            }
            int end = str.size() - ptn[pos+1].minRight;
            if (cp.max != INT_MAX && istr + cp.max < end) {
                end = istr + cp.max;
            }
            if (str.size() - 1 < end) {
                end = str.size() - 1;
            }
            int i = end;
            const string &target = ptn[pos+1].str;
            while ( i >= start) {
                int j = 0;
                while (j < target.size() && target[j] == str[i+j]) {
                    ++j;
                }
                if (j >= target.size() && doMatch(str, i + target.size(), ptn, pos + 2, array)) {
                    array[ai][aj] = YES;
                    return true;
                }
                --i;
            }
            array[ai][aj] = NO;
            return false;
        }
        return false;
    }

    bool isMatch(const char *s, const char *p) {
        vector<pattern> ptn;
        compile(p, ptn);
        string str(s);
        vector<vector<int> > array(str.size() + 1, vector<int>(ptn.size() + 1, NONE));
        return doMatch(str, 0, ptn, 0, array);
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isMatch(argv[1], argv[2]) << endl;
    return 0;
}
