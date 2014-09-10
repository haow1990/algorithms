#include <iostream>
using namespace std;

class Solution {
public:

    void skipBlanks(const char *&s)
    {
        bool blanks[256] = {};
        blanks['\n'] = true;
        blanks['\t'] = true;
        blanks['\r'] = true;
        blanks[' ']  = true;

        // skip blanks
        while (blanks[*s]) {
            ++s;
        }
    }

    bool getNumber(const char *&s)
    {
        if (*s == '+' || *s == '-') {
            ++s;
        }

        bool numBeforeDot = false;
        if (*s >= '0' && *s <= '9') {
            numBeforeDot = true;
            while (*s >= '0' && *s <= '9') {
                ++s;
            }
        }
        if (*s == '.') {
            ++s;
        }
        bool numAfterDot = false;
        if (*s >= '0' && *s <= '9') {
            numAfterDot = true;
            while (*s >= '0' && *s <= '9') {
                ++s;
            }
        }
        return numBeforeDot || numAfterDot;
    }

    bool getInt(const char *&s)
    {
        if (*s == '+' || *s == '-') {
            ++s;
        }
        if (*s < '0' || *s > '9') {
            return false;
        }
        while (*s >= '0' && *s <= '9') {
            ++s;
        }
        return true;
    }
    
    bool isNumber(const char *s) {
        if (s == nullptr) {
            return false;
        }

        skipBlanks(s);
        if (getNumber(s) == false) {
            return false;
        }
        if (*s == 'e' || *s == 'E') {
            ++s;
            if (getInt(s) == false) {
                return false;
            }
        }
        skipBlanks(s);
        return *s == 0;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isNumber(argv[1]) << endl;
    return 0;
}
