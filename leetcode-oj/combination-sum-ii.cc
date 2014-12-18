#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &result, vector<int> &path, map<int, int>::iterator current, map<int, int>::iterator end, int target)
    {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (current == end || current->first > target) {
            return;
        }
        auto next = current;
        ++next;
        int originalSize = path.size();
        for (int i = 0; i <= current->second; ++i) {
            dfs(result, path, next, end, target - current->first * i);
            path.push_back(current->first);
        }
        path.resize(originalSize);
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        map<int, int> nmap;
        for (int n : num) {
            ++nmap[n];
        }
        vector<int> path;
        vector<vector<int> > result;
        dfs(result, path, nmap.begin(), nmap.end(), target);
        return result;
    }
};

int main(int argc, char **argv)
{
    int target = atoi(argv[1]);
    vector<int> candidates;
    for (int i = 2; i < argc; ++i) {
        candidates.push_back(atoi(argv[i]));
    }

    Solution s;
    vector<vector<int> > result = s.combinationSum2(candidates, target);
    for (auto &vec : result) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
