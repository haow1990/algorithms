#include <iostream>
#include <vector>
using namespace std;

void displayMatrix(const vector<vector<int> > &matrix) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j <matrix[i].size(); ++j) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
}

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return;
        }
        int zeroi = -1, zeroj;
        // find a zero cell, use its row and column to store info
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeroi = i;
                    zeroj = j;
                    break;
                }
            }
        }
        // no zero, just return
        if (zeroi == -1) {
            return;
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][zeroj] = 0;
                    matrix[zeroi][j] = 0;
                }
            }
        }
        // set zero
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[zeroi][j] != 0 || j == zeroj) {
                continue;
            }
            for (int i = 0; i < matrix.size(); ++i) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][zeroj] != 0 || i == zeroi) {
                continue;
            }
            for (int j = 0; j < matrix[0].size(); ++j) {
                matrix[i][j] = 0;
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            matrix[i][zeroj] = 0;
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            matrix[zeroi][j] = 0;
        }

    }
};

int main()
{
    vector<vector<int> > matrix{{7,1,0},{9,4,2},{4,6,4},{2,2,8},{5,3,2},{1,3,2},{3,1,8},{7,4,9},{4,9,7},{9,5,8}};

    Solution s;
    s.setZeroes(matrix);
    displayMatrix(matrix);
    return 0;
}
