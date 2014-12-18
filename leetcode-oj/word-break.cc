#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) {
            return true;
        }
        vector<bool> res(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            if (dict.count(s.substr(i))) {
                res[i] = true;
                continue;
            }
            res[i] = false;
            for (int j = i; j < s.size() - 1; ++j) {
                if (dict.count(s.substr(i, j - i + 1)) && res[j + 1]) {
                    res[i] = true;
                    break;
                }
            }
        }
        return res[0];
    
    }
};

int main()
{
    string s = "leetcodeleet";
    unordered_set<string> voc;
    voc.insert("leet");
    voc.insert("code");
    Solution ss;
    cout << ss.wordBreak(s, voc) << endl;
    return 0;
}
