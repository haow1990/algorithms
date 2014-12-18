#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return vector<int>();
        }
        const int M = matrix.size();
        const int N = matrix[0].size();
        vector<int> result(M * N);
        int l = 0, r = N - 1;
        int t = 0, b = M - 1;
        int v = 0;
        while (l <= r && t <= b) {
            for (int j = l; j <= r; ++j) {
                result[v++] = matrix[t][j];
            }
            for (int i = t+1; i <= b; ++i) {
                result[v++] = matrix[i][r];
            }
            if (t != b) {
                for (int j = r-1; j >= l; --j) {
                    result[v++] = matrix[b][j];
                }
            }
            if (l != r) {
                for (int i = b-1; i > t; --i) {
                    result[v++] = matrix[i][l];
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

int main()
{
    vector<vector<int> > matrix{{2,3}};//{{1,2,3}, {4,5,6}, {7,8,9}};
    Solution s;
    vector<int> result = s.spiralOrder(matrix);
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
