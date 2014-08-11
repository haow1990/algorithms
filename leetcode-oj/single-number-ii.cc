#include <cstdlib>
#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int array[sizeof(int) * 8] = {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < sizeof(int) * 8; ++j) {
                array[j] += (A[i] >> j) & 1;
            }
        }
        int result = 0;
        for(int j = 0; j < sizeof(int) * 8; ++j) {
            if (array[j] % 3 != 0) {
                result = result | (1 << j);
            }
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
