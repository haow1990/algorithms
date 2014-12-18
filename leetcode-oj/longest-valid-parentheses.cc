#include <iostream>
#include <string>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int start = -1;
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) {
                    start = i;
                } else {
                    stk.pop();
                    int len = stk.empty() ? i - start : i - stk.top();
                    res = max(res, len);
                }
            }
        }
        return res;
    
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.longestValidParentheses(str) << endl;
    return 0;
}
