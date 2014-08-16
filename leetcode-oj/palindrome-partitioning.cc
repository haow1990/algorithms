#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * [start, end]
 */
bool isPalindrome(const string &s, int start, int end, int *cache)
{
    if (start >= end) {
        return true;
    }
    int idx = start * s.size() + end;
    if (cache[idx] == -1) {
        cache[idx] = 1;
        while (start < end) {
            if (s[start] != s[end]) {
                cache[idx] = 0;
                break;
            }
            ++start;
            --end;
        }
    }
    return cache[idx] == 1;
}

void doPartition(const string &s, size_t start, vector<vector<string> > &result, vector<string> &current, int *cache)
{
    if (start >= s.size()) {
        result.push_back(current);
        return;
    }
    current.push_back(s.substr(start, 1));
    doPartition(s, start + 1, result, current, cache);
    current.pop_back();
    for (size_t len = 2; start + len <= s.size(); ++len) {
        if (isPalindrome(s, start, start + len - 1, cache)) {
            current.push_back(s.substr(start, len));
            doPartition(s, start + len, result, current, cache);
            current.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > result;
        if (s.empty()) {
            return result;
        }
        vector<string> current;
        // -1: not calculated
        // 0 : not palindrome
        // 1 : palidrome
        int *cache = new int[s.size() * s.size()];
        for (int i = 0; i < s.size() * s.size(); ++i) {
            cache[i] = -1;
        }
        doPartition(s, 0, result, current, cache);
        delete cache;
        return result;
    }
};


int main(int argc, char **argv)
{
    string str(argv[1]);
    Solution s;
    vector<vector<string> > result = s.partition(str);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << ' ' << result[i][j];
        }
        cout << endl;
    }

    return 0;
}


