#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n < 1)  return result;
        result.push_back(1);
        result.resize(1 << n);
        for (int i = 2; i <= n; ++i) {
            int delta = (1 << (i-1));
            for (int j = 0; j < delta; ++j) {
                result[delta + j] = delta + result[delta - j - 1];
            }
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> result = s.grayCode(atoi(argv[1]));
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }
    return 0;
}
