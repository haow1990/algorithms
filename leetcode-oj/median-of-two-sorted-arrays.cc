#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (m + n <= 0) {
            return 0.0;
        }
        int mid = (m + n - 1) / 2;
        int i = 0, j = 0;
        while (i + j < mid && i < m && j < n) {
            if (A[i] < B[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        int left = mid - (i + j);
        if (i == m) {
            if ((m + n) % 2 == 1) {
                return B[j + left];
            } else {
                return (B[j + left] + B[j + 1 + left]) / 2.0;
            }
        }
        if (j == n) {
            if ((m + n) % 2 == 1) {
                return A[i + left];
            } else {
                return (A[i + left] + A[i + 1 + left]) / 2.0;
            }
        }
        if ((m + n) % 2 == 1) {
            return A[i] < B[j] ? A[i] : B[j];
        } else {
            int min1, min2;
            if (A[i] < B[j]) {
                min1 = A[i];
                ++i;
            } else {
                min1 = B[j];
                ++j;
            }
            if (i == m) {
                min2 = B[j];
            } else if (j == n) {
                min2 = A[i];
            } else {
                min2 = A[i] < B[j] ? A[i] : B[j];
            }
            return (min1 + min2) / 2.0;
        }
    }
};

int main(int argc, char **argv)
{
    int A[] = {1,1};
    int B[] = {1,2};

    Solution s;
    cout << s.findMedianSortedArrays(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0]))
         << endl;
    return 0;
}
