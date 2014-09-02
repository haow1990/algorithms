#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n <= 0) {
            return 0;
        }
        int *forward = new int[n];
        int *backward = new int[n];
        forward[0] = A[0];
        for (int i = 1; i < n; ++i) {
            if (A[i] < forward[i-1]) {
                forward[i] = forward[i-1];
            } else {
                forward[i] = A[i];
            }
        }
        backward[n-1] = A[n-1];
        for (int i = n - 2; i >= 0; --i) {
            if (A[i] < backward[i+1]) {
                backward[i] = backward[i+1];
            } else {
                backward[i] = A[i];
            }
        }
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (forward[i] > backward[i]) {
                result += backward[i] - A[i];
            } else {
                result += forward[i] - A[i];
            }
        }
        delete[] forward;
        delete[] backward;
        return result;
    }
};

int main(int argc, char **argv) {
    int array[argc - 1];
    for (int i = 1; i < argc; ++i) {
        array[i-1] = atoi(argv[i]);
    }
    Solution s;
    cout << s.trap(array, argc-1) << endl;
    return 0;
}
