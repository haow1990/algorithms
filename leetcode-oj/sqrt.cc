#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        if (x < 2) {
            return x;
        }

        double result = x / 2.0;
        while (true) {
            double d = (result + x / result) / 2;
            if (d - result < 1.0 && result - d < 1.0) {
                return (int)d;
            }
            result = d;
        }
    }
};

int main(int argc, char **argv)
{
    int x = atoi(argv[1]);
    Solution s;
    cout << s.sqrt(x) << endl;
    return 0;
}
