#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int result = INT_MAX;
        int min = INT_MAX;
        for (int i = 0; i < num.size() - 2; ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            while (k > j) {
                int current = num[i] + num[j] + num[k];
                if (current == target) {
                    return current;
                }
                int me = (current-target) * (current-target);
                if (min > me) {
                    min = me;
                    result = current;
                }
                if (current > target) {
                    --k;
                } else {
                    ++j;
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
