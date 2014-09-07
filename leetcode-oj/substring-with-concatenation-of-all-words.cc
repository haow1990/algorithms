#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string, pair<int, int> > lmap;
        for (auto &str : L) {
            auto iter = lmap.find(str);
            if (iter != lmap.end()) {
                iter->second.first += 1;
            } else {
                lmap[str] = make_pair(1, 0);
            }
        }

        vector<int> result;
        if (L.empty() || L.front().empty()) {
            for (int i = 0; i < S.size(); ++i) {
                result.push_back(i);
            }
            return result;
        }
        int len = L.front().size();
        int total = L.size() * len;
        for (int i = 0; i + total <= S.size(); ++i) {
            bool ok = true;
            for (int j = 0; j < L.size(); ++j) {
                auto iter = lmap.find(S.substr(i + j * len, len));
                if (iter == lmap.end() || iter->second.first <= iter->second.second) {
                    ok = false;
                    break;
                }
                iter->second.second += 1;
            }
            if (ok) {
                result.push_back(i);
            }
            for (auto &pr : lmap) {
                pr.second.second = 0;
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    string S(argv[1]);
    vector<string> L;
    for (int i = 2; i < argc; ++i) {
        L.push_back(argv[i]);
    }
    Solution sol;
    vector<int> result = sol.findSubstring(S, L);
    for (int i : result) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
