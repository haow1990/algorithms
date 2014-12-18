#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (s.empty()) 
        vector<vector<string> > result(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            if (dict.count(s.substr(i)) > 0) {
                result[i].push_back(s.substr(i));
            }
            for (int j = i; j < s.size() - 1; ++j) {
                if (dict.count(s.substr(i, j - i + 1)) == 0) {
                    continue;
                }
                for (auto &str : result[j+1]) {
                    result[i].push_back(s.substr(i, j - i + 1) + " " + str);
                }
            }
        }
        return result[0];
    }

};

int main()
{
//    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
//    unordered_set<string> voc;
//    voc.insert("a");
//    voc.insert("aa");
//    voc.insert("aaa");
//    voc.insert("aaaa");
//    voc.insert("aaaaa");
//    voc.insert("aaaaaa");
//    voc.insert("aaaaaaa");
//    voc.insert("aaaaaaaa");
//    voc.insert("aaaaaaaaa");
//    voc.insert("aaaaaaaaaa");
    string s = "catsanddog";
    unordered_set<string> voc;
    voc.insert("cat");
    voc.insert("cats");
    voc.insert("and");
    voc.insert("sand");
    voc.insert("dog");
    Solution ss;
    vector<string> result = ss.wordBreak(s, voc);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
