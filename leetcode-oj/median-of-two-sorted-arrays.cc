#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int min(int x, int y) {
        return (x < y) ? x : y;
    }

    int findKth(int A[], int m, int B[], int n, int k) {
        if (m > n) {
            return findKth(B, n, A, m, k);
        }
        if (m == 0) {
            return B[k-1];
        }
        if (k == 1) {
            return min(A[0], B[0]);
        }
        int pa = min(k / 2, m);
        int pb = k - pa;
        if (A[pa-1] == B[pb-1]) {
            return A[pa-1];
        } else if (A[pa-1] < B[pb-1]) {
            return findKth(A+pa, m-pa, B, n, k-pa);
        } else {
            return findKth(A, m, B+pb, n-pb, k-pb);
        }
    }
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int len = m + n;
        if (len % 2 != 0) {
            return findKth(A, m, B, n, len / 2 + 1);
        } else {
            return (findKth(A, m, B, n, len / 2) + findKth(A, m, B, n, len / 2 + 1)) / 2.0;
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
