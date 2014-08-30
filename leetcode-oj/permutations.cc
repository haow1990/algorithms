#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void doperm(const vector<int> &num, vector<vector<int> > &result, vector<int> &path, int idx, vector<bool> &visited)
    {
        if (idx >= num.size()) {
            result.push_back(path);
            return;
        }
        for (size_t i = 0; i < visited.size(); ++i) {
            if (visited[i])
                continue;
            visited[i] = true;
            path.push_back(num[i]);
            doperm(num, result, path, idx + 1, visited);
            path.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() <= 0) {
            return result;
        }
        vector<int> path;
        vector<bool> visited(num.size(), false);
        doperm(num, result, path, 0, visited);
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

