#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result;
        if (strs.empty()) {
            return result;
        }
        int i = 0;
        while (i < strs[0].size()) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != c) {
                    return result;
                }
            }
            result.push_back(c);
            ++i;
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<string> strs;
    for (int i = 1; i < argc; ++i) {
        strs.push_back(argv[i]);
    }
    Solution s;
    cout << s.longestCommonPrefix(strs) << endl;
    return 0;
}
