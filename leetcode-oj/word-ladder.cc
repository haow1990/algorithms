#include <iostream>
#include <utility>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return 1;
        }
        size_t n = start.size();
        queue<pair<string, int> > q;
        q.push(make_pair(start, 1));
        dict.erase(start);
        while (q.empty() == false) {
            string &current = q.front().first;
            for (size_t i = 0; i < n; ++i) {
                char originalC = current[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalC) continue;
                    current[i] = c;
                    if (current == end) return q.front().second + 1;
                    else if (dict.count(current) > 0) {
                        q.push(make_pair(current, q.front().second + 1));
                        dict.erase(current);
                    }
                }
                current[i] = originalC;
            }
            q.pop();
        }
        return 0;
    }
};

int main(int argc, char **argv)
{
    string start(argv[1]);
    string end(argv[2]);
    unordered_set<string> dict;
    for (int i = 3; i < argc; ++i) {
        dict.insert(argv[i]);
    }

    Solution s;
    cout << s.ladderLength(start, end, dict) << endl;
    return 0;
}
