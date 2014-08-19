#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        char cmap[256];
        bool empty[256];
        for (int i = 0; i < sizeof(cmap); ++i) {
            cmap[i] = i;
            empty[i] = true;
        }
        for (char i = '0'; i <= '9'; ++i) {
            empty[i] = false;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            cmap[c] = c - 'a' + 'A';
            empty[c] = false;
            empty[c - 'a' + 'A'] = false;
        }
        int i = 0;
        int j = s.size();
        --j;
        while (true) {
            while (i < j && empty[s[i]])
                ++i;
            while (i < j && empty[s[j]])
                --j;
            if (i >= j)
                return true;
            if (cmap[s[i]] != cmap[s[j]])
                return false;
            ++i;
            --j;
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.isPalindrome(str) << endl;
    return 0;
}
