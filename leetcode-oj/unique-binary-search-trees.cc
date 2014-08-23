#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;
        vector<int> nums(n + 1);
        nums[0] = 1;
        nums[1] = 1;
        for (size_t i = 2; i < nums.size(); ++i) {
            nums[i] = 0;
            for (size_t j = 0; j < i; ++j)
                nums[i] += nums[j] * nums[i - j -1];
        }
        return nums.back();
    }
};

int main(int argc, char **argv)
{
    Solution s;
    cout << s.numTrees(atoi(argv[1])) << endl;
    return 0;
}

