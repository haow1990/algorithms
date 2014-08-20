#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        vector<int> left(prices.size());
        int min = prices[0];
        left[0] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int current = prices[i] - min;
            if (current > left[i-1]) {
                left[i] = current;
            } else {
                left[i] = left[i-1];
            }
            if (min > prices[i]) {
                min = prices[i];
            }
        }

        vector<int> right(prices.size());
        int max = prices.back();
        right.back() = 0;
        for (int i = prices.size() - 2; i >= 0; --i) {
            int current = max - prices[i];
            if (current > right[i+1]) {
                right[i] = current;
            } else {
                right[i] = right[i+1];
            }
            if (max < prices[i]) {
                max =  prices[i];
            }
        }

        int result = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (result < left[i] + right[i]) {
                result = left[i] + right[i];
            }
        }
        return result;
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
