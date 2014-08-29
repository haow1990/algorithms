#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int max = A[0];
        int current = max;
        for (int i = 1; i < n; ++i) {
            if (current > 0) {
                current += A[i];
            } else {
                current = A[i];
            }
            if (current > max) {
                max = current;
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    int array[argc - 1];
    for (int i = 1; i < argc; ++i) {
        array[i-1] = atoi(argv[i]);
    }
    Solution s;
    cout << s.maxSubArray(array, argc - 1) << endl;
    return 0;
}
