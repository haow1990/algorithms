#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            switch (c) {
                case '(':
                    stk.push('(');
                    break;

                case ')':
                    if (stk.empty() || stk.top() != '(') {
                        return false;
                    }
                    stk.pop();
                    break;
                    
                case '{':
                    stk.push('{');
                    break;

                case '}':
                    if (stk.empty() || stk.top() != '{') {
                        return false;
                    }
                    stk.pop();
                    break;

                case '[':
                    stk.push('[');
                    break;

                case ']':
                    if (stk.empty() || stk.top() != '[') {
                        return false;
                    }
                    stk.pop();
                    break;

                default:
                    return false;
            }
        }
        return stk.empty();
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.isValid(str) << endl;
    return 0;
}
