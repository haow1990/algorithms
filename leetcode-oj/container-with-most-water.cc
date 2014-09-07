#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int min(int x, int y) {
        return x > y ? y : x;
    }
    int maxArea(vector<int> &height) {
        int max = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
            int now = min(height[i], height[j]) * (j - i);
            if (now > max) {
                max = now;
            }
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    vector<int> height;
    for (int i = 1; i < argc; ++i) {
        height.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.maxArea(height) << endl;
    return 0;
}
