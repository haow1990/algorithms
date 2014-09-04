#include <iostream>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    map<int, vector<vector<int> > > cache;

    const vector<vector<int> > &combine(set<int> &candidates, int target)
    {
        auto iter = cache.find(target);
        if (iter != cache.end()) {
            return iter->second;
        }
        iter = cache.insert(make_pair(target, vector<vector<int> >())).first;
        vector<vector<int> > &result = iter->second;
        for (int i : candidates) {
            if (target - i >= 0) {
                for (auto &vec : combine(candidates, target - i)) {
                    if (vec.empty() == false && i > vec.front()) {
                        continue;
                    }
                    result.resize(result.size() + 1);
                    result.back().push_back(i);
                    result.back().insert(result.back().end(), vec.begin(), vec.end());
                }
            }
        }
        return result;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        cache.clear();
        cache[0] = vector<vector<int> >(1);
        set<int> sc;
        for (int i : candidates) {
            sc.insert(i);
        }
        return combine(sc, target);
    }
};

int main(int argc, char **argv)
{
    int target = atoi(argv[1]);
    vector<int> candidates;
    for (int i = 2; i < argc; ++i) {
        candidates.push_back(atoi(argv[i]));
    }

    Solution s;
    vector<vector<int> > result = s.combinationSum(candidates, target);
    for (auto &vec : result) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
