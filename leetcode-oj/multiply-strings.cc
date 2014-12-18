#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void addNum(unordered_map<int, int> &result, int idx, int val) {
        while (val != 0) {
            val += result[idx];
            result[idx] = val % 10;
            val /= 10;
            ++idx;
        }
    }
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        unordered_map<int, int> result;
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                int val = (num1[i] - '0') * (num2[j] - '0');
                addNum(result, i + j, val);
            }
        }
        int digits = 0;
        for (auto &p : result) {
            if (p.second != 0 && p.first > digits) {
                digits = p.first;
            }
        }
        string str(digits + 1, 0);
        for (int i = 0; i <= digits; ++i) {
            str[digits-i] = result[i] + '0';
        }
        return str;
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
