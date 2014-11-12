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
        int desired[256] = {};
        int existed[256] = {};
        for (char c : T) {
            ++desired[c];
        }
        int totalChars = count_if(desired, desired + 256, [](int val) {return val != 0;});
        int start = 0;
        string result;
        for (int i = 0; i < S.size(); ++i) {
            ++existed[S[i]];
            if (desired[S[i]] == existed[S[i]]) {
                --totalChars;
            }
            if (totalChars > 0) {
                continue;
            }
            while (existed[S[start]] > desired[S[start]]) {
                --existed[S[start]];
                ++start;
            }
            if (result.empty() || i - start + 1 < result.size()) {
                result = S.substr(start, i - start + 1);
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
