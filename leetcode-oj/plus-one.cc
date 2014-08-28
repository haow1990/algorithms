#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carry) {
                digits[i] += 1;
                if (digits[i] >= 10) {
                    digits[i] -= 10;
                    carry = true;
                } else {
                    carry = false;
                }
            } else {
                break;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(int argc, char **argv)
{
    vector<int> digits;
    for (int i = 1; i < argc; ++i) {
        digits.push_back(atoi(argv[i]));
    }
    Solution s;
    vector<int> result = s.plusOne(digits);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}
