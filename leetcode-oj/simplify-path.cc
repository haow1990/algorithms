#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() < 2) {
            return path;
        }
        const string DOT = ".";
        const string DOTDOT = "..";
        vector<string> splits;
        size_t i = 0;
        bool absolute = false;
        if (path[0] == '/') {
            absolute = true;
            ++i;
        }
        while (i < path.size()) {
            while (i < path.size() && path[i] == '/') {
                ++i;
            }
            if (i >= path.size()) {
                break;
            }
            size_t start = i;
            while (i < path.size() && path[i] != '/') {
                ++i;
            }
            string split = path.substr(start, i - start);
            if (split == DOT) {
                continue;
            } else if (split == DOTDOT) {
                if (splits.empty() == false) {
                    splits.pop_back();
                }
            } else {
                splits.push_back(split);
            }
        }
        string result;
        if (absolute) {
            result.push_back('/');
        }
        for (auto &split : splits) {
            result += split;
            result.push_back('/');
        }
        if (result.size() > 1 && result.back() == '/') {
            result.pop_back();
        }
        if (result.empty()) {
            result.push_back('.');
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    string path(argv[1]);
    Solution s;
    cout << s.simplifyPath(path) << endl;
    return 0;
}
