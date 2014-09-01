#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while (i < n && A[i] != elem) {
            ++i;
        }
        int k = i + 1;
        while (k < n) {
            if (A[k] != elem) {
                A[i] = A[k];
                ++i;
            }
            ++k;
        }
        return i;
    }
};

int main(int argc, char **argv)
{
    int elem = atoi(argv[1]);
    int A[argc-2];
    for (int i = 2; i < argc; ++i) {
        A[i-2] = atoi(argv[i]);
    }
    Solution s;
    int len = s.removeElement(A, argc - 2, elem);
    for (int i = 0; i < len; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
