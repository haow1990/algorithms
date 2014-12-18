#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int N = matrix.size();
        int l = 0, r = N - 1;
        int t = 0, b = N - 1;
        while (l < r) {
            for (int i = 0; l + i < r; ++i) {
                int tmp = matrix[t][l+i];
                matrix[t][l+i] = matrix[b-i][l];
                matrix[b-i][l] = matrix[b][r-i];
                matrix[b][r-i] = matrix[t+i][r];
                matrix[t+i][r] = tmp;
            }
            ++l;
            --r;
            ++t;
            --b;
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
