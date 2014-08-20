#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i-1])
                max += prices[i] - prices[i-1];
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
