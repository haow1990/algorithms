#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    void swap(int A[], int i, int j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
    int firstMissingPositive(int A[], int n) {
        int iPosMax = 0;
        // partition positives and non-positives
        for (int i = 0; i < n; ++i) {
            if (A[i] > 0) {
                swap(A, iPosMax++, i);
            } else {
                A[i] = 1;
            }
        }
        for (int i = 0; i < iPosMax; ++i) {
            int num = A[i] > 0 ? A[i] : -A[i];
            if (A[num-1] > 0 && num <= iPosMax) {
                A[num-1] = 0 - A[num-1];
            }
        }
        int missing = 0;
        while (missing < iPosMax && A[missing] < 0) {
            ++missing;
        }
        return missing + 1;
    }
};

int main(int argc, char **argv) {
    int array[argc - 1];
    for (int i = 1; i < argc; ++i) {
        array[i-1] = atoi(argv[i]);
    }
    Solution s;
    cout << s.firstMissingPositive(array, argc - 1) << endl;
    return 0;
}
