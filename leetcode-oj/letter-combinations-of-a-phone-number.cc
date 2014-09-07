#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> nmap;

    bool dfs(vector<string> &result, const string &digits, size_t i, string &path)
    {
        if (i >= digits.size()) {
            result.push_back(path);
            return true;
        }
        if (digits[i] < '2' || digits[i] > '9') {
            return false;
        }
        for (char c : nmap[digits[i] - '2']) {
            path.push_back(c);
            if (dfs(result, digits, i + 1, path) == false) {
                return false;
            }
            path.pop_back();
        }
        return true;
    }

    vector<string> letterCombinations(string digits) {
        if (nmap.empty()) {
            nmap.push_back("abc");
            nmap.push_back("def");
            nmap.push_back("ghi");
            nmap.push_back("jkl");
            nmap.push_back("mno");
            nmap.push_back("pqrs");
            nmap.push_back("tuv");
            nmap.push_back("wxyz");
        }
        vector<string> result;
        string path;
        dfs(result, digits, 0, path);
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
