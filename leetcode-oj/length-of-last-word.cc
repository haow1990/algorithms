#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        bool over = true;
        while (*s != '\0') {
            if (*s == ' ') {
                over = true;
            } else if (over) {
                over = false;
                len = 1;
            } else {
                len += 1;
            }
            ++s;
        }
        return len;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.lengthOfLastWord(argv[1]) << endl;
    return 0;
}
