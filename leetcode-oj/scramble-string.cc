#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool sameChars(const char *start, const char *end, const char *cmp) {
        int sum1 = 0, sum2 = 0;
        int prod1 = 1, prod2 = 1;
        while (start != end) {
            sum1 += *start;
            prod1 *= *start;
            sum2 += *cmp;
            prod2 *= *cmp;

            ++start;
            ++cmp;
        }

        return sum1 == sum2 && prod1 == prod2;
    }

    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        if (s1.empty()) {
            return true;
        }
        const size_t LEN = s1.size();
        vector<vector<vector<bool> > > array(LEN, vector<vector<bool> >(LEN, vector<bool>(LEN, false)));
        for (size_t i = 0; i < LEN; ++i) {
            for (size_t k = 0; k < LEN; ++k) {
                array[i][i][k] = (s1[i] == s2[k]);
            }
        }
        for (size_t step = 1; step < LEN; ++step) {
            for (size_t i = 0; i + step < LEN; ++i) {
                size_t j = i + step;
                for (size_t k = 0; k+j-i < LEN; ++k) {
                    for (size_t x = i; x < j; ++x) {
                        if (array[i][x][k] && array[x+1][j][k+x-i+1] ||
                                array[i][x][k+j-x] && array[x+1][j][k]) {
                            array[i][j][k] = true;
                            break;
                        }
                    }

                }
            }
        }

        return array[0][LEN-1][0];
    }
};
int main(int argc, char **argv)
{
    string s1(argv[1]);
    string s2(argv[2]);
    Solution s;
    cout << s.isScramble(s1, s2) << endl;
    return 0;
}
