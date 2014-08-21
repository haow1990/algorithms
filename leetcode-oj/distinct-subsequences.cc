#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.size() < T.size()) {
            return 0;
        }
        vector<vector<int> > array(S.size() + 1, vector<int>(T.size() + 1));
        for (size_t i = 0; i <= S.size(); ++i) {
            array[i][0] = 1;
        }
        for (size_t j = 1; j <= T.size(); ++j) {
            array[0][j] = 0;
        }
        for (size_t j = 1; j <= T.size(); ++j) {
            for (size_t i = j; i <= S.size(); ++i) {
                array[i][j] = array[i-1][j];
                if (S[i-1] == T[j-1])
                    array[i][j] += array[i-1][j-1];
            }
        }
        return array[S.size()][T.size()];
    }
};

int main(int argc, char **argv)
{
    string s(argv[1]);
    string t(argv[2]);
    Solution sol;
    cout << sol.numDistinct(s, t) << endl;
    return 0;
}
