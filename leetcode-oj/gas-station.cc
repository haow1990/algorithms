#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty()) {
            return -1;
        }
        int totalGas = 0;
        int totalCost = 0;
        int sum = 0;
        int start = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
            if (sum < 0) {
                sum = gas[i] - cost[i];
                start = i;
            } else {
                sum += gas[i] - cost[i];
            }
        }
        if (totalCost <= totalGas) {
            return start;
        } else {
            return -1;
        }

    }
};

int main(int argc, char **argv)
{
    vector<int> gas;
    vector<int> cost;
    for (int i = 1; i < argc - 1; i+=2) {
        gas.push_back(atoi(argv[i]));
        cost.push_back(atoi(argv[i+1]));
    }
    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
