#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
    map<string, vector<string> > rmap;
public:
    vector<string> &wordBreakHelper(const string &s, unordered_set<string> &dict) {
        map<string, vector<string> >::iterator riter = rmap.find(s);
        if (riter != rmap.end()) {
            return riter->second;
        }

        vector<string> &values = rmap.insert(make_pair(s, vector<string>())).first->second;
        if (dict.count(s) > 0) {
            values.push_back(s);
        }
        for (size_t i = 1; i < s.size(); ++i) {
            string left = s.substr(0, i);
            if (dict.count(left) == 0) {
                continue;
            }
            vector<string> s2 = wordBreak(s.substr(i, s.size() - i), dict);
            for (size_t j = 0; j < s2.size(); ++j) {
                values.push_back(left + " " + s2[j]);
            }
        }
        return values;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        return wordBreakHelper(s, dict);
//        const int DIM = s.size();
//        map<string, vector<string> > result;
//        string tmp;
//        for (size_t step = 1; step <= DIM; ++step) {
//            for (size_t start = 0; start <= DIM - step; ++start) {
//                tmp.assign(s, start, step);
//                if (result.count(tmp) > 0) {
//                    continue;
//                }
//                vector<string> &values = result.insert(make_pair(tmp, vector<string>())).first->second;
//                size_t end = start + step;
//                for (size_t i = start + 1; i <= end; ++i) {
//                    string left = s.substr(start, i - start);
//                    if (dict.count(left) == 0) {
//                        continue;
//                    }
//                    if (i == end) {
//                        values.push_back(left);
//                        continue;
//                    }
//                    vector<string> &s2 = result[s.substr(i, end - i)];
//                    for (size_t j = 0; j < s2.size(); ++j) {
//                        values.push_back(left + " " + s2[j]);
//                    }
//                }
//                cout << tmp << ' ' << values.size() << endl;
//            }
//        }
//        
//        return result[s];
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
