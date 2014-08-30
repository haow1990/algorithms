#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int *min = new int[n];
        min[n-1] = -1;
        min[0] = 0;
        int max = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i > max) {
                break;
            }
            for (int j = max + 1; j <= A[i] + i && j < n; ++j) {
                min[j] = min[i] + 1;
            }
            if (max < A[i] + i) {
                max = A[i] + i;
            }
        }
        int result = min[n-1];
        delete[] min;
        return result;
    }
};

int main(int argc, char **argv)
{
    int *array = new int[argc - 1];
    for (int i  = 1; i < argc; ++i) {
        array[i-1] = atoi(argv[i]);
    }
    Solution s;
    cout << s.jump(array, argc - 1) << endl;
    return 0;
}
