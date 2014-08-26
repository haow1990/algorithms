#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<int> path;

    void com(int n, int i, int k)
    {
        if (k == 0) {
            result.push_back(path);
        } else if (n - i + 1 >= k) {
            com(n, i+1, k);
            path.push_back(i);
            com(n, i+1, k-1);
            path.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        result.clear();
        path.clear();
        if (k <= 0 || n <= 0)
            return result;
        com(n, 1, k);
        return result;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    Solution sol;
    vector<vector<int> > result = sol.combine(n, k);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "--";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
