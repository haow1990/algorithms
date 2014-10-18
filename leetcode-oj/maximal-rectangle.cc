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

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        const size_t m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > height(m, vector<int>(n));
        // first line
        for (size_t i = 0; i < n; ++i) {
            height[0][i] = matrix[0][i] - '0';
        }
        // other lines
        for (size_t i = 1; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    height[i][j] = 0;
                } else {
                    height[i][j] = height[i-1][j] + 1;
                }
            }
        }
        
        int max = 0;
        for (size_t i = 0; i < m; ++i) {
            int tmp = largestRectangleArea(height[i]);
            if (tmp > max) {
                max = tmp;
            }
        }
        
        return max;
    }
};
