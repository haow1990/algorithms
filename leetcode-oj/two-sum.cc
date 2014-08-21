#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mp;
        vector<int> result;
        for (size_t i = 0; i < numbers.size(); ++i) {
            auto iter = mp.find(target - numbers[i]);
            if (iter != mp.end()) {
                result.push_back(iter->second + 1);
                result.push_back(i + 1);
                break;
            } else {
                mp[numbers[i]] = i;
            }
        }
        return result;
    }
};
