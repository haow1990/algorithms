#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tripple {
    int sum;
    int i;
    int j;
    tripple(int ss, int ii, int jj)
        : sum(ss), i(ii), j(jj)
    {}
};

struct tripple_cmp {
    bool operator()(const tripple &t1, const tripple &t2)
    {
        if (t1.sum < t2.sum) {
            return false;
        } else {
            return true;
        }
    }
};

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        size_t H = grid.size();
        size_t W = grid[0].size();
        vector<vector<int> > path(H, vector<int>(W, -1));
        priority_queue<tripple, vector<tripple>, tripple_cmp> q;
        q.push(tripple(grid[0][0], 0, 0));
        while (q.empty() == false) {
            tripple tp = q.top();
            q.pop();
            if (tp.i == H - 1 && tp.j == W - 1) {
                return tp.sum;
            }
            if (path[tp.i][tp.j] < 0) {
                path[tp.i][tp.j] = tp.sum;
                // right
                if (tp.i + 1 < H
                        && path[tp.i+1][tp.j] == -1) {
                    q.push(tripple(tp.sum + grid[tp.i+1][tp.j], tp.i+1, tp.j));
                }
                // bottom
                if (tp.j + 1 < W
                        && path[tp.i][tp.j+1] == -1) {
                    q.push(tripple(tp.sum + grid[tp.i][tp.j+1], tp.i, tp.j+1));
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<vector<int> > grid//{{1,2,1,1,1,1,1,1},{10,1,2,1,1,1,1,1}};
    {{5,4,2,9,6,0,3,5,1,4,9,8,4,9,7,5,1},{3,4,9,2,9,9,0,9,7,9,4,7,8,4,4,5,8},{6,1,8,9,8,0,3,7,0,9,8,7,4,9,2,0,1},{4,0,0,5,1,7,4,7,6,4,1,0,1,0,6,2,8},{7,2,0,2,9,3,4,7,0,8,9,5,9,0,1,1,0},{8,2,9,4,9,7,9,3,7,0,3,6,5,3,5,9,6},{8,9,9,2,6,1,2,5,8,3,7,0,4,9,8,8,8},{5,8,5,4,1,5,6,6,3,3,1,8,3,9,6,4,8},{0,2,2,3,0,2,6,7,2,3,7,3,1,5,8,1,3},{4,4,0,2,0,3,8,4,1,3,3,0,7,4,2,9,8},{5,9,0,4,7,5,7,6,0,8,3,0,0,6,6,6,8},{0,7,1,8,3,5,1,8,7,0,2,9,2,2,7,1,5},{1,0,0,0,6,2,0,0,2,2,8,0,9,7,0,8,0},{1,1,7,2,9,6,5,4,8,7,8,5,0,3,8,1,5},{8,9,7,8,1,1,3,0,1,2,9,4,0,1,5,3,1},{9,2,7,4,8,7,3,9,2,4,2,2,7,8,2,6,7},{3,8,1,6,0,4,8,9,8,0,2,5,3,5,5,7,5},{1,8,2,5,7,7,1,9,9,8,9,2,4,9,5,4,0},{3,4,4,1,5,3,3,8,8,6,3,5,3,8,7,1,3}};
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            cout << grid[i][j] << ' ';
        }
        cout << endl;
    }
    Solution s;
    cout << s.minPathSum(grid) << endl;
    return 0;
}
