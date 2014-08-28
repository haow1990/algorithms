#include <iostream>
#include <string>
#include <climits>
#include <map>
#include <utility>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        string result;
        if (T.empty() || T.size() > S.size()) {
            return result;
        }
        map<char, pair<int, int> > idx;
        for (char c : T) {
            auto iter = idx.find(c);
            if (iter != idx.end()) {
                iter->second.first += 1;
            } else {
                idx[c] = make_pair(1, 0);
            }
        }
        int found = 0;
        int lastMin = -1;
        for (size_t i = 0; i < S.size(); ++i) {
            auto iter = idx.find(S[i]);
            if (iter == idx.end()) {
                continue;
            }
            if (lastMin < 0) {
                lastMin = i;
            }
            iter->second.second += 1;
            if (iter->second.second == iter->second.first) {
                found += 1;
            }
            if (found < idx.size()) {
                continue;
            }
            while (lastMin < i){
                auto iter = idx.find(S[lastMin]);
                if (iter != idx.end()) {
                    auto &pr = iter->second;
                    if (pr.first < pr.second) {
                        --pr.second;
                    } else {
                        break;
                    }
                }
                ++lastMin;
            }
            if (result.empty() || i - lastMin + 1 < result.size()) {
                result = S.substr(lastMin, i - lastMin + 1);
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    string S(argv[1]);
    string T(argv[2]);
    Solution sol;
    string re = sol.minWindow(S, T);
    cout << re << endl;
    return 0;
}
