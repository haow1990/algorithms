#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    
    void sub(const vector<int> &s, size_t i)
    {
        if (i >= s.size()) {
            result.push_back(path);
        } else {
            sub(s, i+1);
            path.push_back(s[i]);
            sub(s, i+1);
            path.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        for (size_t i = S.size(); i > 0; --i) {
            for (size_t j = 0; j + 1 < i; ++j) {
                if (S[j] > S[j+1]) {
                    int tmp = S[j];
                    S[j] = S[j+1];
                    S[j+1] = tmp;
                }
            }
        }
        result.clear();
        path.clear();
        sub(S, 0);
        return result;
    }
};

int main(int argc, char **argv)
{
    vector<int> s;
    for (int i = 1; i < argc; ++i) {
        s.push_back(atoi(argv[i]));
    }
    Solution sol;
    vector<vector<int> > result = sol.subsets(s);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "--";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
