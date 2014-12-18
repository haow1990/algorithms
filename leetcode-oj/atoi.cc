#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if (str == nullptr) {
            return 0;
        }
        bool blank[256] = {};
        blank[' '] = true;
        blank['\t'] = true;
        blank['\n'] = true;
        blank['\r'] = true;
        
        int i = 0;
        // skip none digits
        while (str[i] != '\0' && blank[str[i]]) {
            ++i;
        }
        // sign
        bool negative = false;
        if (str[i] == '-') {
            ++i;
            negative = true;
        } else if (str[i] == '+') {
            ++i;
        }
        int result = 0;
        bool overflow = false;
        while (str[i] >= '0' && str[i] <= '9') {
            int d = str[i] - '0';
            if (result > (INT_MAX - d) / 10) {
                overflow = true;
                break;
            }
            result = result * 10 + d;
            ++i;
        }
        if (overflow) {
            return negative ? INT_MIN : INT_MAX;
        } else {
            return negative ? -result : result;
        }
    
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.atoi(argv[1]) << endl;
    return 0;
}
