#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = result ^ A[i];
        }
        return result;
    }
};


int main(int argc, char **argv)
{
    int array[argc - 1];
    for (int i = 1; i < argc; ++i) {
        array[i - 1] = atoi(argv[i]);
    }
    Solution s;
    cout << s.singleNumber(array, argc - 1) << endl;
    return 0;
}
