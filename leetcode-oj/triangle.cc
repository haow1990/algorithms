#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.empty()) {
            return 0;
        }
        vector<int> tmp = triangle.back();
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                if (tmp[j] < tmp[j+1]) {
                    tmp[j] = tmp[j] + triangle[i][j];
                } else {
                    tmp[j] = tmp[j+1] + triangle[i][j];
                }
            }
        }
        return tmp[0];
    }
};

int main(int argc, char **argv)
{
    vector<vector<int> > triangle{{2}};//, {3,4}, {6,5,7}, {4,1,8,3}};
    Solution s;
    cout << s.minimumTotal(triangle) << endl;
    return 0;
}
