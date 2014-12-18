#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> numset;
        for (int i = 0; i < numbers.size(); ++i) {
            auto iter = numset.find(target - numbers[i]);
            if (iter != numset.end()) {
                return vector<int>{iter->second + 1, i + 1};
            } else {
                numset[numbers[i]] = i;
            }
        }
        return vector<int>();
    }
};
