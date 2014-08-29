#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if (x == 0.0) {
            return 0.0;
        }
        if (n == 0) {
            return 1.0;
        }
        if (n < 0) {
            x = 1 / x;
            n = 0 - n;
        }
        double result = 1.0;
        while (n > 0) {
            if (n & 1) {
                result = result * x;
            }
            x = x * x;
            n = (n >> 1);
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    double x = atof(argv[1]);
    int n = atoi(argv[2]);
    int k = atoi(argv[3]);
    Solution s;
    cout << s.pow(x, n) << endl;
    while (k > 0) {
        s.pow(x, n);
        --k;
    }
    return 0;
}

