#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
     vector<vector<int> > generateMatrix(int n) {
        if (n < 0) {
            n = -n;
        }
        vector<vector<int> > result(n, vector<int>(n));
        int l = 0, r = n - 1;
        int t = 0, b = n - 1;
        int k = 0;
        while (l <= r) {
            for (int j = l; j <= r; ++j) {
                result[t][j] = ++k;
            }
            for (int i = t + 1; i <= b; ++i) {
                result[i][r] = ++k;
            }
            if (t != b) {
                for (int j = r - 1; j >= l; --j) {
                    result[b][j] = ++k;
                }
            }
            if (l != r) {
                for (int i = b - 1; i > t; --i) {
                    result[i][l] = ++k;
                }
            }
            ++l;
            --r;
            ++t;
            --b;
        }
        return result;
    
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    vector<vector<int> > result = s.generateMatrix(n);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
