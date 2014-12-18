#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(vector<string> &result, string &path, vector<string> &nums, string &digits, int i) {
        if (i >= digits.size()) {
            result.push_back(path);
            return;
        }
        for (char c : nums[digits[i] - '0']) {
            path[i] = c;
            dfs(result, path, nums, digits, i + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> nums{
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> result;
        string path(digits.size(), 0);
        dfs(result, path, nums, digits, 0);
        return result;
    
    }
};

int main(int argc, char **argv)
{
    string digits(argv[1]);
    Solution s;
    for (string &str : s.letterCombinations(digits)) {
        cout << str << endl;
    }

    return 0;
}
