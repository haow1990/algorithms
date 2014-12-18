#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> vertical(n, false);
        vector<bool> slash(n * 2, false);
        vector<bool> backslash(n * 2, false);
        function<void(int)> backtrack = [&](int i) -> void {
            if (i >= n) {
                ++res;
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (vertical[j] || slash[i+j] || backslash[i-j+n-1]) {
                    continue;
                }
                vertical[j] = true;
                slash[i+j] = true;
                backslash[i-j+n-1] = true;
                backtrack(i+1);
                vertical[j] = false;
                slash[i+j] = false;
                backslash[i-j+n-1] = false;
            }
        };
        backtrack(0);
        return res;
    }

};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    Solution s;
    int result = s.totalNQueens(n);
    cout << result << endl;
    return 0;
}
