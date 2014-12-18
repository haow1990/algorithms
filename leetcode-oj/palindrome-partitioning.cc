#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) {
            return vector<vector<string> >();
        }
        const int N = s.size();
        // partition(s[i..]) => result[i]
        vector<vector<vector<string> > > result(s.size());
        vector<vector<bool> > palindrome(N, vector<bool>(N));
        int end = N - 1;
        for (int i = N - 1; i >= 0; --i) {
            if (s[i] == s[end] && (end - i <= 2 || palindrome[i+1][end-1])) {
                palindrome[i][end] = true;
                result[i].push_back(vector<string>{s.substr(i)});
            } else {
                palindrome[i][end] = false;
            }
            for (int j = i; j < N - 1; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || palindrome[i+1][j-1])) {
                    palindrome[i][j] = true;
                    for (vector<string> &vec : result[j+1]) {
                        result[i].push_back(vector<string>{s.substr(i, j-i+1)});
                        result[i].back().insert(result[i].back().end(), vec.begin(), vec.end());
                    }
                } else {
                    palindrome[i][j] = false;
                }
            } 
        }
        return result[0];
    }

};


int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    vector<vector<string> > result = s.partition(str);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << ' ' << result[i][j];
        }
        cout << endl;
    }

    return 0;
}


