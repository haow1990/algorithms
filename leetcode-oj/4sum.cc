#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct xy {
    int x;
    int y;

    xy(int xx, int yy)
        : x(xx), y(yy)
    {}
};

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        unordered_map<int, vector<xy> > twosum;
        for (int i = 0; i < num.size(); ++i) {
            for (int j = i + 1; j < num.size(); ++j) {
                int sum = num[i] + num[j];
                auto iter = twosum.find(sum);
                if (iter == twosum.end()) {
                    iter = twosum.insert(make_pair(sum, vector<xy>())).first;
                }
                iter->second.push_back(xy(i, j));
            }
        }
        vector<vector<int> > result;
        unordered_set<int> visited1;
        unordered_set<int> visited2;
        unordered_set<int> visited3;
        unordered_set<int> visited4;
        vector<int> vv(4);
        while (twosum.empty() == false) {
            auto iter = twosum.begin();
            int a = iter->first;
            int b = target - a;
            auto that = twosum.find(b);
            if (that != twosum.end()) {
                for (auto xy1 : iter->second) {
                    for (auto xy2 : that->second) {
                        if (xy1.x == xy2.x || xy1.x == xy2.y
                                || xy1.y == xy2.x || xy1.y == xy2.y) {
                            continue;
                        }
                        vv[0] = num[xy1.x];
                        vv[1] = num[xy1.y];
                        vv[2] = num[xy2.x];
                        vv[3] = num[xy2.y];
                        sort(vv.begin(), vv.end());
                        int v1 = vv[0] + vv[1] + vv[2] + vv[3];
                        int v2 = vv[0] * vv[0] + vv[1] * vv[1] + vv[2] * vv[2] + vv[3] * vv[3];
                        int v3 = vv[0] * vv[0] * vv[0] + vv[1] * vv[1] * vv[1]
                            + vv[2] * vv[2] * vv[2] + vv[3] * vv[3] * vv[3];
                        int v4 = vv[0] * vv[0] * vv[0] * vv[0] + vv[1] * vv[1] * vv[1] * vv[1]
                            + vv[2] * vv[2] * vv[2] * vv[2] + vv[3] * vv[3] * vv[3] * vv[3];
                        if (visited1.count(v1) > 0 && visited2.count(v2) > 0
                                && visited3.count(v3) > 0 && visited4.count(v4) > 0) {
                            continue;
                        }
                        result.push_back(vv);
                        visited1.insert(v1);
                        visited2.insert(v2);
                        visited3.insert(v3);
                        visited4.insert(v4);
                    }
                }
            }

            twosum.erase(a);
            twosum.erase(b);
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
