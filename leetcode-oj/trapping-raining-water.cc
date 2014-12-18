#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> leftmax(n);
        leftmax[0] = A[0];
        for (int i = 1; i < n; ++i) {
            leftmax[i] = max(leftmax[i-1], A[i]);
        }
        vector<int> rightmax(n);
        rightmax[n-1] = A[n-1];
        for (int j = n - 2; j >= 0; --j) {
            rightmax[j] = max(rightmax[j+1], A[j]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += min(leftmax[i], rightmax[i]) - A[i];
        }
        return res;
    
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
