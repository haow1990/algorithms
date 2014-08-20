#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min = prices[0];
        int max = 0;
        for (size_t i = 0; i < prices.size(); ++i) {
            int current = prices[i] - min;
            if (current > max) {
                max = current;
            }
            if (min > prices[i]) {
                min = prices[i];
            }
        }
        return max;
    }
};

int main(int argc, char **argv)
{
    vector<int> vec;
    vec.reserve(argc -1);
    for (int i = 1; i < argc; ++i) {
        vec.push_back(atoi(argv[i]));
    }
    Solution s;
    cout << s.maxProfit(vec) << endl;
    return 0;
}
