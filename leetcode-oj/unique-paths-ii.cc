#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int array[100][100];
        array[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 1; i < m; ++i) {
            array[i][0] = (1 - obstacleGrid[i][0]) && array[i-1][0];
        }
        for (int j = 1; j < n; ++j) {
            array[0][j] = (1 - obstacleGrid[0][j]) && array[0][j-1];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    array[i][j] = 0;
                } else {
                    array[i][j] = array[i-1][j] + array[i][j-1];
                }
            }
        }
        return array[m-1][n-1];

    }
};
    }
};

int main(int argc, char **argv)
{
    return 0;
}
