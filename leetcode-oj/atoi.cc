#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if (str == NULL)
            return 0;
        bool whites[256] = {};
        whites[' '] = true;
        whites['\t'] = true;
        whites['\n'] = true;
        whites['\r'] = true;
        
        bool digits[256] = {};
        for (char c = '0'; c <= '9'; ++c) {
            digits[c] = true;
        }
        
        int i = 0;
        while (str[i] && whites[str[i]]) {
            ++i;
        }
        if (!digits[str[i]] && str[i] != '+' && str[i] != '-') {
            return 0;
        }
        bool negative = false;
        if (str[i] == '+') {
            ++i;
        } else if (str[i] == '-') {
            ++i;
            negative = true;
        }
        int number = 0;
        bool overflow = false;
        while (digits[str[i]]) {
            if (number > INT_MAX / 10) {
                overflow = true;
                break;
            }
            number = number * 10 + str[i] - '0';
            if (number < 0) {
                overflow = true;
                break;
            }
            ++i;
        }
        if (negative) {
            if (overflow)   return INT_MIN;
            else    return -1 * number;
        } else {
            if (overflow)   return INT_MAX;
            else    return number;
        }
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.atoi(argv[1]) << endl;
    return 0;
}
