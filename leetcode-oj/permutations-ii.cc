#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<int> > &result, vector<int> &path, int pi, unordered_map<int, int> &nmap) {
        if (pi >= path.size()) {
            result.push_back(path);
            return;
        }
        for (auto &pr : nmap) {
            if (pr.second > 0) {
                --pr.second;
                path[pi] = pr.first;
                backtrack(result, path, pi + 1, nmap);
                ++pr.second;
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        unordered_map<int, int> nmap;
        for (int n : num) {
            ++nmap[n];
        }
        vector<vector<int> > result;
        vector<int> path(num.size());
        backtrack(result, path, 0, nmap);
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
    vector<vector<int> > result = s.permute(num);

    for (auto &vec : result) {
        for (auto i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}

