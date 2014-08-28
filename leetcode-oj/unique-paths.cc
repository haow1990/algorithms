#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int array[100][100];
        for (int i = 0; i < m; ++i) {
            array[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            array[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                array[i][j] = array[i-1][j] + array[i][j-1];
            }
        }
        return array[m-1][n-1];
    }
};

int main(int argc, char **argv)
{
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    Solution s;
    cout << s.uniquePaths(m, n) << endl;
    return 0;
}
