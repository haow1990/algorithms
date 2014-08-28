#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        if (target < matrix.front().front() || target > matrix.back().back()) {
            return false;
        }
        size_t WIDTH = matrix[0].size();
        int i = 0, j = matrix.size() * matrix[0].size();
        while (i < j) {
            int mid = (i + j) / 2;
            int mida = mid / WIDTH;
            int midb = mid % WIDTH;
            if (target == matrix[mida][midb]) {
                return true;
            } else if (target < matrix[mida][midb]) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return false;
    }
};

int main(int argc, char **argv)
{
    vector<vector<int> > matrix{{1,3,5,9}, {10,11,16,20}, {23,20,34,50}};
    int target = atoi(argv[1]);
    Solution s;
    cout << s.searchMatrix(matrix, target) << endl;
    return 0;
}
