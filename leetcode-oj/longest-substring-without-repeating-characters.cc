#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        unordered_map<char, int> cidx;
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto iter = cidx.find(s[i]);
            if (iter == cidx.end()) {
                cidx[s[i]] = i;
            } else {
                for (int j = left; j < iter->second; ++j) {
                    cidx.erase(s[j]);
                }
                left = iter->second + 1;
                iter->second = i;
            }
            if (max < cidx.size()) {
                max = cidx.size();
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
