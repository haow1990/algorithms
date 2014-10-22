#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) {
                return mid;
            }
            // if A[left..mid] is ordered
            if (A[left] < A[mid]) {
                if (left < mid && A[left] <= target && target <= A[mid-1]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // right part is ordered
                if (mid < right && A[mid+1] <= target && target <= A[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};

int main(int argc, char **argv)
{
    int target = atoi(argv[1]);
    int *array = new int[argc-2];
    for (int i = 2; i < argc; ++i) {
        array[i-2] = atoi(argv[i]);
    }
    Solution s;
    cout << s.search(array, argc - 2, target) << endl;
    return 0;
}
