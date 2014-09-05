#include <iostream>
#include <string>
#include <stack>
#include <climits>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> left;
        int last = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                left.push(i);
            } else {
                if (left.empty()) {
                    last = i;
                } else {
                    left.pop();
                    int start;
                    if (left.empty() == false) {
                        start = left.top();
                    } else {
                        start = last;
                    }
                    if (i - start > max) {
                        max = i - start;
                    }
                }
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.longestValidParentheses(str) << endl;
    return 0;
}
