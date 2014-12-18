#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        if (s == nullptr) {
            return false;
        }
        auto eatblanks = [&](){
            while (*s == ' ') {
                ++s;
            }
        };
        auto eatunsigned = [&]()->bool{
            if (*s < '0' || *s > '9') {
                return false;
            }
            while (*s >= '0' && *s <= '9') {
                ++s;
            }
            return true;
        };
        auto eatsigned = [&]()->bool {
            if (*s == '+' || *s == '-') {
                ++s;
            }
            return eatunsigned();
        };
        auto eatnumber = [&]()->bool {
            bool beforedot = eatsigned();
            if (*s == '.') {
                ++s;
            }
            bool afterdot = eatunsigned();
            return beforedot || afterdot;
        };
        eatblanks();
        if (eatnumber() == false) {
            return false;
        }
        if (*s == 'e' || *s == 'E') {
            ++s;
            if (eatsigned() == false) {
                return false;
            }
        }
        eatblanks();
        return *s == '\0';
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.isNumber(argv[1]) << endl;
    return 0;
}
