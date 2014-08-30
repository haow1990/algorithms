#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int n = matrix.size();
        int mid2 = n - 1;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                 int di2 = mid2 - i * 2;
                 int dj2 = mid2 - j * 2;
                 int tri = (mid2 - dj2) / 2;
                 int trj = (mid2 + di2) / 2;
                 int bri = (mid2 + di2) / 2;
                 int brj = (mid2 + dj2) / 2;
                 int bli = (mid2 + dj2) / 2;
                 int blj = (mid2 - di2) / 2;

                 int me = matrix[i][j];
                 matrix[i][j] = matrix[bli][blj];
                 matrix[bli][blj] = matrix[bri][brj];
                 matrix[bri][brj] = matrix[tri][trj];
                 matrix[tri][trj] = me;
            }
        }
    }
};

void display(const vector<vector<int> > &matrix)
{
    for (auto &vec : matrix) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    vector<vector<int> > matrix(n, vector<int>(n));
    int i = 0;
    for (auto &vec : matrix) {
        for (int &n : vec) {
            n = ++i;
        }
    }
    display(matrix);
    cout << endl;

    Solution s;
    s.rotate(matrix);
    display(matrix);

    return 0;
}
