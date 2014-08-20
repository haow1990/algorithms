#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        result.resize(rowIndex + 1);       
        result.front() = 1;
        result.back() = 1;
        for (int i = 1; i <= rowIndex / 2; ++i) {
            cout << i << result[i-1] << ' ' << (rowIndex - i + 1) << endl;
            result[i] = ((long long)result[i-1]) * (rowIndex - i + 1) / i;
            result[rowIndex - i] = result[i];
        }
        return result;
    }
};

int main(int argc, char **argv)
{
    int num = atoi(argv[1]);
    Solution s;
    vector<int> result = s.getRow(num);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
