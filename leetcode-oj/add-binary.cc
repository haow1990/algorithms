#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        auto ia = a.rbegin();
        auto ib = b.rbegin();
        int carry = 0;
        while (ia != a.rend() && ib != b.rend()) {
            int d = *ia - '0' + *ib - '0' + carry;
            carry = d > 1 ? 1 : 0;
            result.push_back('0' + (d&1));
            ++ia;
            ++ib;
        }
        auto ii = ia;
        auto ie = a.rend();
        if (ia == a.rend()) {
            ii = ib;
            ie = b.rend();
        }
        while (ii != ie) {
            int d = *ii - '0' + carry;
            carry = d > 1 ? 1 : 0;
            result.push_back('0' + (d&1));
            ++ii;
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

