#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() < 2) {
            return 0;
        }
        const int N = s.size();
        vector<vector<bool> > pal(N, vector<bool>(N, false));
        vector<int> result(N);
        for (int i = N - 1; i >= 0; --i) {
            result[i] = N - i - 1;
            for (int j = i; j < N; ++j) {
                if (s[i] == s[j]
                     && (j - i < 2 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                    if (j == N-1) {
                        result[i] = 0;
                    } else if (result[j+1] < result[i]) {
                        result[i] = result[j+1] + 1;
                    }
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
    cout << s.minCut(str) << endl;
    return 0;
}
