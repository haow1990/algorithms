#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct myhash{
    size_t operator()(const tuple<int, int, int> &tpl)const {
        return get<0>(tpl) * get<0>(tpl) + get<1>(tpl) * get<1>(tpl) + get<2>(tpl) * get<2>(tpl);
    }
};

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        unordered_multimap<int, pair<int, int> > combs;
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                combs.insert(make_pair(num[i] + num[j], make_pair(i, j)));
            }
        }
        unordered_set<tuple<int, int, int>, myhash> rset;
        vector<vector<int> > result;
        for (int i = 0; i < num.size(); ++i) {
            auto range = combs.equal_range(0 - num[i]);
            for (auto iter = range.first; iter != range.second; ++iter) {
                if (i == iter->second.first || i == iter->second.second) {
                    continue;
                }
                vector<int> v{num[i], num[iter->second.first], num[iter->second.second]};
                sort(v.begin(), v.end());
                if (rset.insert(make_tuple(v[0], v[1], v[2])).second) {
                    result.push_back(v);
                }
            }
        }
        return result;
    
    }
};

int main(int argc, char **argv)
{
    vector<int> num;
    for (int i = 1; i < argc; ++i) {
        num.push_back(atoi(argv[i]));
    }
    Solution s;
    for (auto &vec : s.threeSum(num)) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
