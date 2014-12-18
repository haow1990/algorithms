#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
struct strkey {
    int count[26];
    strkey() {
        bzero(count, sizeof(count));
    }
    strkey(const string &str) {
        bzero(count, sizeof(count));
        for (char c : str) {
            ++count[c-'a'];
        }
    }
};

bool operator==(const strkey &k1, const strkey &k2) {
    for (int i = 0; i < 26; ++i) {
        if (k1.count[i] != k2.count[i]) {
            return false;
        }
    }
    return true;
}

struct strkeyhash {
    size_t operator()(const strkey &sk)const {
        size_t re = 0;
        for (int i = 0; i < 26; ++i) {
            re += sk.count[i] * (i + 1);
        }
        return re;
    }
};

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<strkey, vector<string>, strkeyhash> smap;
        for (string &s : strs) {
            smap[strkey(s)].push_back(s);
        }
        vector<string> result;
        for (auto &pr : smap) {
            if (pr.second.size() > 1) {
                result.insert(result.end(), pr.second.begin(), pr.second.end());
            }
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
    vector<string> result = s.anagrams(strs);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}


