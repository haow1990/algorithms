#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) {
            return s;
        }

        string result;
        int gap = 2 * nRows - 2;
        // first line
        for (size_t i = 0; i < s.size(); i += gap) {
            result.push_back(s[i]);
        }
        // middle
        for (size_t j = 1; j < nRows - 1; ++j) {
            for (size_t i = j; i < s.size(); i += gap) {
                result.push_back(s[i]);
                if (i + gap - j * 2 < s.size()) {
                    result.push_back(s[i + gap - j * 2]);
                }
            }
        }
        // last line
        for (size_t i = nRows - 1; i < s.size(); i += gap) {
            result.push_back(s[i]);
        }

        return result;
    }
};

int main(int argc, char **argv)
{
    string s(argv[1]);
    int n = atoi(argv[2]);
    Solution sol;
    cout << sol.convert(s, n) << endl;
    return 0;
}
