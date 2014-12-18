#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        bool chars[256] = {};
        int s = 0;
        for (int e = 0; e < str.size(); ++e) {
            if (chars[str[e]]) {
                while (str[s] != str[e]) {
                    chars[str[s]] = false;
                    ++s;
                }
                ++s;
            }
            result = max(result, e - s + 1);
            chars[str[e]] = true;
        }
        return result;
    
    }
};

int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}
