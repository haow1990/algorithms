#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (haystack == nullptr || needle == nullptr) {
            return nullptr;
        }
        const int len1 = strlen(haystack);
        const int len2 = strlen(needle);
        for (int i = 0; i <= len1 - len2; ++i) {
            int j = 0;
            while (j < len2 && haystack[i+j] == needle[j]) {
                ++j;
            }
            if (j == len2) {
                return haystack + i;
            }
        }
        return nullptr;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.strStr(argv[1], argv[2]) << endl;
    return 0;
}
