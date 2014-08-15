#include <cstdlib>
#include <iostream>
using namespace std;


class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x < 0) {
            negative = true;
            x = 0 - x;
        }
        int result = 0;
        while (x > 0) {
            result = result * 10 + x % 10;
            x = x / 10;
        }
        if (negative) {
            result = 0 - result;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    int num = atoi(argv[1]);
    Solution s;
    cout << s.reverse(num) << endl;
    return 0;
}
