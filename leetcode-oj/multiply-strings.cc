#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string result("0");
        if (num1 == result || num2 == result) {
            return result;
        }
        for (char &c : num1) {
            c -= '0';
        }
        for (char &c : num2) {
            c -= '0';
        }
        result[0] = 0;
        for (int i = num1.size() - 1, ir = 0; i >= 0; --i, ++ir) {
            int carry = 0;
            for (int j = num2.size() - 1, jr = ir; j >= 0; --j, ++jr) {
                if (jr >= result.size()) {
                    result.resize(jr + 1, 0);
                }
                int carry2 = (result[jr] + num1[i] * num2[j] + carry) / 10;
                result[jr] = (result[jr] + num1[i] * num2[j] + carry) % 10;
                carry = carry2;
            }
            if (carry != 0) {
                result.push_back(carry);
            }
        }
        for (char &c : result) {
            c += '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char **argv)
{
    string num1(argv[1]);
    string num2(argv[2]);
    Solution s;
    cout << s.multiply(num1, num2) << endl;
    return 0;
}
