#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0;
        while (i < n && target > A[i]) {
            ++i;
        }
        return i;
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
    cout << s.searchInsert(array, argc-2, target) << endl;
    return 0;
}
