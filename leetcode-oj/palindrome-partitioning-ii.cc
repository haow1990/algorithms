#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2) {
            return 0;
        }
        vector<vector<bool> > palindrome(s.size(), vector<bool>(s.size()));
        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            int e = s.size() - 1;
            if (s[i] == s[e] && (e - i <= 2 || palindrome[i+1][e-1])) {
                palindrome[i][e] = true;
            } else {
                palindrome[i][e] = false;
            }
            result[i] = palindrome[i][e] ? 0 : s.size() - i;
            for (int j = i; j + 1 < s.size(); ++j) {
                if (s[i] == s[j] && (j - i <= 2 || palindrome[i+1][j-1])) {
                    palindrome[i][j] = true;
                    result[i] = min(result[i], 1 + result[j+1]);
                } else {
                    palindrome[i][j] = false;
                }
            }
        }
        return result[0];
    
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.minCut(str) << endl;
    return 0;
}
