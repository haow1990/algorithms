#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Manacher’s Algorithm
    // http://blog.csdn.net/hopeztm/article/details/7932245
    string longestPalindrome(string s) {
        string tmp(s.size() * 2 + 1, 0);
        for (int i = 0; i < s.size(); ++i) {
            tmp[i * 2] = 0;
            tmp[i * 2 + 1] = s[i];
        }
        tmp.back() = 0;
        string result;
        vector<int> radius(tmp.size());
        int i = 0;
        while (i < tmp.size()) {
            int r = 1;
            while (i - r >= 0 && i + r < tmp.size() && tmp[i-r] == tmp[i+r]) {
                ++r;
            }
            radius[i] = r - 1;
            if (r - 1 > result.size()) {
                result = s.substr((i-r+1)/2, r-1);
            }
            
            int j = 1;
            while (j < r && i - j - radius[i-j] > i - r + 1) {
                radius[i+j] = radius[i-j];
                ++j;
            }
            i += j;
        }
        return result;
    
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.longestPalindrome(argv[1]) << endl;
    return 0;
}
