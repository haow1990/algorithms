#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int abs(int val) {
        return val < 0 ? -val : val;
    }

    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) {
            return 0;
        }
        sort(num.begin(), num.end());
        int result = num[0] + num[1] + num[2];
        for (int i = 0; i < num.size(); ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == target) {
                    return target;
                }
                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }
                if (sum < target) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return result;
    
    }
};


int main(int argc, char **argv)
{
    int target = atoi(argv[1]);
    vector<int> num;
    for (int i = 2; i < argc; ++i) {
        num.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.threeSumClosest(num, target) << endl;
    return 0;
}
