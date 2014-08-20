#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        result.resize(numRows);
        for (int i = 0; i < numRows; ++i) {
            result[i].resize(i+1);
            result[i][0] = 1;
            result[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    int num = atoi(argv[1]);
    Solution s;
    vector<vector<int> > vec = s.generate(num);
    for (int i = 0; i < vec.size(); ++i) {
        for (int j  =0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
