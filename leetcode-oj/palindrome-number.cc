#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0) {
            return false;
        }
        int y = 0;
        while (x >= y) {
            y = y * 10 + x % 10;
            if (x == y)
                return true;
            x = x / 10;
            if (x == y)
                return true;
            if (y == 0)
                return false;
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isPalindrome(atoi(argv[1])) << endl;
    return 0;
}
