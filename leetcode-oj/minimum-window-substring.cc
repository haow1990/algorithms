#include <iostream>
#include <string>
#include <climits>
#include <map>
#include <utility>
#include <unordered_map>
using namespace std;

#include <tuple>
class Solution {
public:
    string minWindow(string S, string T) {
        if (T.empty()) {
            return T;
        }
        //      wanted char   wanted  got
        unordered_map<char, tuple<int, int> > cmap;
        for (char c : T) {
            auto iter = cmap.insert(make_pair(c, make_tuple(0, 0))).first;
            get<0>(iter->second) += 1;
            cout << c << ' ' << get<0>(iter->second) << endl;
        }
        string result;
        // left means current start of substring
        int left = 0;
        int unfinished_chars = cmap.size();
        for (int right = 0; right < S.size(); ++right) {
            auto cmapiter = cmap.find(S[right]);
            if (cmapiter == cmap.end()) {
                continue;
            }
            get<1>(cmapiter->second) += 1;
            if (get<1>(cmapiter->second) == get<0>(cmapiter->second)) {
                --unfinished_chars;
            }
            if (unfinished_chars > 0) {
                continue;
            }
            // S[left..right] contains all the chars in T
            // move left pointer towards right to find the shortest
            while (left < right) {
                auto leftiter = cmap.find(S[left]);
                if (leftiter == cmap.end()) {
                    ++left;
                    continue;
                }
                if (get<1>(leftiter->second) > get<0>(leftiter->second)) {
                    get<1>(leftiter->second) -= 1;
                    ++left;
                } else {
                    break;
                }
            }
            if (result.empty() || right - left + 1 < result.size()) {
                result = S.substr(left, right - left + 1);
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
