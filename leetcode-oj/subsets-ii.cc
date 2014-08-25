#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;
    map<int, int> nums;

    void form(map<int, int>::iterator iter)
    {
        if (iter == nums.end()) {
            result.push_back(path);
            return;
        }
        size_t original = path.size();
        for (int i = 0; i <= iter->second; ++i) {
            auto next = iter++;
            form(iter);
            iter = next;
            path.push_back(iter->first);
        }
        path.resize(original);
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        nums.clear();
        for (auto iter = S.begin(); iter != S.end(); ++iter) {
            auto mpiter = nums.find(*iter);
            if (mpiter == nums.end()) {
                nums[*iter] = 1;
            } else {
                mpiter->second += 1;
            }
        }
        
        result.clear();
        path.clear();
        form(nums.begin());
        return result;
    }
};

int main()
{
    vector<int> s{1,2,2};
    Solution sol;
    vector<vector<int> > result = sol.subsetsWithDup(s);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
