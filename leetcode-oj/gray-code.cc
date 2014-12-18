#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.resize(1 << n);
        result[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int count = (1 << (i - 1));
            for (int j = 0; j < count; ++j) {
                result[count + j] = count + result[count-j-1];
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
