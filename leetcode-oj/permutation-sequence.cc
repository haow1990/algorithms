#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int FACTORIALS[] = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

class Solution {
public:
    void dfs(string &result, vector<int> &remaining, int facts[10], int idx, int k) {
        if (remaining.size() == 1) {
            result.back() = remaining.front();
            return;
        }
        int i = k / facts[remaining.size() - 1];
        result[idx] = remaining[i];
        remaining.erase(remaining.begin() + i);
        dfs(result, remaining, facts, idx + 1, k % facts[remaining.size()]);
    }
    
    string getPermutation(int n, int k) {
        int facts[10] = {0, 1};
        for (int i = 2; i < 10; ++i) {
            facts[i] = facts[i-1] * i;
        }
        if (n < 1 || k > facts[n] || k < 1) {
            return string();
        }
        
        string result(n, 0);
        vector<int> remaining(n);
        for (int i = 0; i < n; ++i) {
            remaining[i] = i + '1';
        }
        dfs(result, remaining, facts, 0, k-1);
        return result;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    Solution s;
    cout << s.getPermutation(n, k) << endl;
    return 0;
}
