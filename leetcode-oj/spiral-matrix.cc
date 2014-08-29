#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        result.reserve(m * n);
        
        int layers = (m + 1) / 2;
        if (layers > (n + 1) / 2) {
            layers = (n + 1) / 2;
        }
        for (int t = 0; t < layers; ++t) {
            int mini = t;
            int minj = t;
            int maxi = m - 1 -t;
            int maxj = n - 1 -t;
            for (int j = minj; j <= maxj; ++j) {
                result.push_back(matrix[mini][j]);
            }

            for (int i = mini + 1; i <= maxi; ++i) {
                result.push_back(matrix[i][maxj]);
            }
            if (mini == maxi) {
                continue;
            }

            for (int j = maxj - 1; j >= minj; --j) {
                result.push_back(matrix[maxi][j]);
            }

            if (minj == maxj) {
                continue;
            }
            for (int i = maxi - 1; i > mini; --i) {
                result.push_back(matrix[i][minj]);
            }
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
