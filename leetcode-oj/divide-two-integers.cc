#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = true;
        unsigned int uend, usor;
        if (dividend < 0) {
            uend = -dividend;
            positive = false;
        } else {
            uend = dividend;
        }
        if (divisor == 0) {
            return positive ? INT_MAX : INT_MIN;
        }
        if (divisor < 0) {
            usor = -divisor;
            positive = !positive;
        } else {
            usor = divisor;
        }
        int shift = 1;
        while (uend > (usor << shift)) {
            shift += 1;
        }
        int result = 0;
        while (uend >= usor) {
            if (uend >= (usor << shift)) {
                result += (1 << shift);
                uend -= (usor << shift);
            }
            --shift;
        }
        return positive ? result : -result;
    }
};

int main(int argc, char **argv)
{
    int end = atoi(argv[1]);
    int sor = atoi(argv[2]);
    Solution s;
    cout << s.divide(end, sor) << endl;
    return 0;
}
