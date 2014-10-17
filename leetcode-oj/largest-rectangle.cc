#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) {
            return 0;
        }
        height.push_back(0);
        stack<int> stk;
        int max = 0;
        int i = 0;
        while (i < height.size()) {
            if (stk.empty() || height[i] >= height[stk.top()]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                int area = height[t] * (stk.empty() ? i : (i - stk.top() - 1));
                if (area > max) {
                    max = area;
                }
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
    cout << s.largestRectangleArea(height) << endl;
    return 0;
}
