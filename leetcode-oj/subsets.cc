#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &result, vector<int> &path, vector<int> &S, int is) {
        if (is >= S.size()) {
            result.push_back(path);
            return;
        }
        // no add
        dfs(result, path, S, is + 1);
        // add 
        path.push_back(S[is]);
        dfs(result, path, S, is + 1);
        path.pop_back();
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> path;
        dfs(result, path, S, 0);
        return result;
    }

};

int main(int argc, char **argv)
{
    vector<int> s;
    for (int i = 1; i < argc; ++i) {
        s.push_back(atoi(argv[i]));
    }
    Solution sol;
    vector<vector<int> > result = sol.subsets(s);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << "--";
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
