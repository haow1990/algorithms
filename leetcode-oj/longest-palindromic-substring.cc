#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Manacher’s Algorithm
    // http://blog.csdn.net/hopeztm/article/details/7932245
    string longestPalindrome(string s) {
        string t;
        t.push_back(0);
        for (char c : s) {
            t.push_back(c);
            t.push_back(0);
        }
        const size_t L = t.size();
        vector<int> d(L, -1);
        for (int i = 0; i < L; ++i) {
            if (d[i] >= 0) {
                continue;
            }
            // find d[i]
            int dd = 0;
            while (i-dd-1>=0 && i+dd+1<L &&
                    t[i-dd-1]==t[i+dd+1]) {
                ++dd;
            }
            d[i] = dd;
            for (int j = 1; j < dd; ++j) {
                if (i - j - d[i-j] > i - dd) {
                    d[i+j] = d[i-j];
                }
            }
        }
        int max = 0;
        int maxi = 0;
        for (int i = 0; i < d.size(); ++i) {
            if (max < d[i]) {
                max = d[i];
                maxi = i;
            }
        }
        int start = (maxi - max) / 2;
        return s.substr(start, max);
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.longestPalindrome(argv[1]) << endl;
    return 0;
}
