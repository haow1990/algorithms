#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i = 0;
        while (i < n && target > A[i]) {
            ++i;
        }
        int j = i;
        while (j < n && target == A[j]) {
            ++j;
        }
        if (i == j) {
            i = -1;
            j = 0;
        }
        vector<int> result{i, j-1};
        return result;
    }
};

int main(int argc, char **argv)
{
    int array[argc - 2];
    int target = atoi(argv[1]);
    for (int i = 2; i < argc; ++i) {
        array[i-2] = atoi(argv[i]);
    }
    Solution s;
    vector<int> vec = s.searchRange(array, argc-2, target);
    cout << vec[0] << ' ' << vec[1] << endl;
    return 0;
}
