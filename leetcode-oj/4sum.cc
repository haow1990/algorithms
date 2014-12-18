#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct myhash {
    size_t operator()(const tuple<int, int, int, int> &tpl) const {
        return get<0>(tpl) * get<0>(tpl)
               + get<1>(tpl) * get<1>(tpl)
               + get<2>(tpl) * get<2>(tpl)
               + get<3>(tpl) * get<3>(tpl);
    }
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unordered_map<int, vector<pair<int, int> > > twosum;
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                twosum[num[i] + num[j]].push_back(make_pair(i, j));
            }
        }
        vector<vector<int> > result;
        unordered_set<tuple<int, int, int, int>, myhash> rset;
        vector<int> vv(4);
        for (auto &kv1 : twosum) {
            auto kv2 = twosum.find(target - kv1.first);
            if (kv2 == twosum.end()) {
                continue;
            }
            for (auto &pr1 : kv1.second) {
                for (auto &pr2 : kv2->second) {
                    if (pr1.first == pr2.first || pr1.first == pr2.second
                        || pr1.second == pr2.first || pr1.second == pr2.second) {
                        continue;
                    }
                    vv[0] = num[pr1.first];
                    vv[1] = num[pr1.second];
                    vv[2] = num[pr2.first];
                    vv[3] = num[pr2.second];
                    sort(vv.begin(), vv.end());
                    if (rset.insert(make_tuple(vv[0], vv[1], vv[2], vv[3])).second) {
                        result.push_back(vv);
                    }
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
    for (auto &vec : s.fourSum(num, target)) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
