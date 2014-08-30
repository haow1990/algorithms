#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
     vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result(n, vector<int>(n));

        int layers = (n + 1) / 2;
        int x = 1;
        for (int t = 0; t < layers; ++t) {
            int mini = t;
            int minj = t;
            int maxi = n - 1 -t;
            int maxj = n - 1 -t;
            for (int j = minj; j <= maxj; ++j) {
                result[mini][j] = x++;
            }

            for (int i = mini + 1; i <= maxi; ++i) {
                result[i][maxj] = x++;
            }
            if (mini == maxi) {
                continue;
            }

            for (int j = maxj - 1; j >= minj; --j) {
                result[maxi][j] = x++;
            }

            if (minj == maxj) {
                continue;
            }
            for (int i = maxi - 1; i > mini; --i) {
                result[i][minj] = x++;
            }
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
