#include <cstdlib>
#include <iostream>
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

struct xyz {
    int x;
    int y;
    int z;

    xyz(int xx, int yy, int zz)
        : x(xx), y(yy), z(zz)
    {}
};

struct myhash {
    size_t operator()(const xyz &val) const
    {
        return val.x * val.x + val.y * val.y + val.z * val.z;
    }
};

bool operator==(const xyz &val1, const xyz &val2)
{
    return val1.x == val2.x
            && val1.y == val2.y
            && val1.z == val2.z;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
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
        unordered_set<xyz, myhash> visited;
        vector<int> vv(3);
        for (int i = 0; i < num.size(); ++i) {
            auto iter = twosum.find(0 - num[i]);
            if (iter == twosum.end()) {
                continue;
            }
            for (auto xy1 : iter->second) {
                if (i == xy1.x || i == xy1.y) {
                    continue;
                }
                vv[0] = num[i];
                vv[1] = num[xy1.x];
                vv[2] = num[xy1.y];
                sort(vv.begin(), vv.end());
                xyz xyz1(vv[0], vv[1], vv[2]);
                if (visited.count(xyz1) > 0) {
                    continue;
                }
                result.push_back(vv);
                visited.insert(xyz1);
            }

            twosum.erase(iter);
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
