#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> result_stack;
        for (vector<string>::iterator iter = tokens.begin();
                iter != tokens.end(); ++iter) {
            const string &expr = *iter;
            switch (*expr.rbegin()) {
                case '+':
                    *(result_stack.end() - 2) = *(result_stack.end() - 2) + *(result_stack.end() - 1);
                    result_stack.erase(result_stack.end() - 1, result_stack.end());
                    break;
                case '-':
                    *(result_stack.end() - 2) = *(result_stack.end() - 2) - *(result_stack.end() - 1);
                    result_stack.erase(result_stack.end() - 1, result_stack.end());
                    break;
                case '*':
                    *(result_stack.end() - 2) = *(result_stack.end() - 2) * *(result_stack.end() - 1);
                    result_stack.erase(result_stack.end() - 1, result_stack.end());
                    break;
                case '/':
                    *(result_stack.end() - 2) = *(result_stack.end() - 2) / *(result_stack.end() - 1);
                    result_stack.erase(result_stack.end() - 1, result_stack.end());
                    break;
                default:
                    int num = 0;
                    size_t i = 0;
                    if (expr[0] == '-' || expr[0] == '+') {
                        i = 1;
                    }
                    for (;i < expr.size(); ++i) {
                        num = num * 10 + (expr[i] - '0');
                    }
                    if (expr[0] == '-') {
                        num = num * -1;
                    }
                    result_stack.push_back(num);
            }
        }
        return result_stack[0];
    }
};

int main()
{
    vector<string> polish;
    polish.push_back("3");
    polish.push_back("-4");
    polish.push_back("+");

    Solution s;
    cout << s.evalRPN(polish) << endl;
    return 0;
}
