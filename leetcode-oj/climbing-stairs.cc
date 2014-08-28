#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        int a1 = 1;
        int a2 = 1;
        for (int i = 2; i <= n; ++i) {
            int tmp = a1 + a2;
            a1 = a2;
            a2 = tmp;
        }
        return a2;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    cout << s.climbStairs(n) << endl;
    return 0;
}
