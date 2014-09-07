#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void dfs(vector<string> &result, int left, int remainings, string &path)
    {
        if (left + remainings == 0) {
            result.push_back(path);
            return;
        }
        if (left > 0) {
            path.push_back(')');
            dfs(result, left - 1, remainings, path);
            path.pop_back();
        }
        if (remainings > 0) {
            path.push_back('(');
            dfs(result, left + 1, remainings - 1, path);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        dfs(result, 0, n, path);
        return result;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    for (string &str : result) {
        cout << str << endl;
    }
    return 0;
}
