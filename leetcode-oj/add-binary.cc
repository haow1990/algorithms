#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) {
            return addBinary(b, a);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string result;
        int carry = 0;
        for (int i = 0; i < b.size(); ++i) {
            int res = a[i] - '0' + b[i] - '0' + carry;
            result.push_back('0' + (res & 1));
            carry = (res >> 1);
        }
        for (int i = b.size(); i < a.size(); ++i) {
            int res = a[i] - '0' + carry;
            result.push_back('0' + (res & 1));
            carry = (res >> 1);
        }
        if (carry) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    
    }
};

int main(int argc, char **argv)
{
    string a(argv[1]);
    string b(argv[2]);
    Solution s;
    cout << s.addBinary(a, b) << endl;
    return 0;
}

