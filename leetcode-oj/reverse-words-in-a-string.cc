#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        bool spaceMap[256] = {};
        spaceMap['\t'] = true;
        spaceMap['\n'] = true;
        spaceMap[' ' ] = true;

        string ans;
        string::iterator wordEnd;
        string::iterator wordStart = s.end() - 1;
        while (wordStart >= s.begin()) {
            // find end of a word
            while (wordStart >= s.begin() && spaceMap[*wordStart]) {
                --wordStart;
            }
            wordEnd = wordStart;
            // find start of a word
            while (wordStart >= s.begin() && !spaceMap[*wordStart]) {
                --wordStart;
            }
            if (wordStart < wordEnd) {
                ans.append(wordStart + 1, wordEnd + 1);
                ans.push_back(' ');
            }   
        }
        if (ans.begin() != ans.end() && *ans.rbegin() == ' ') {
            ans.erase(ans.end() - 1, ans.end());
        }

        ans.swap(s);
    }
};

int main()
{
    string s("");
    cout << ">>" << s << "<<" << endl;
    Solution sol;
    sol.reverseWords(s);
    cout << ">>" << s << "<<" << endl;

    return 0;
}
