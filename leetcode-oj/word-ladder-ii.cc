#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<vector<string> > &result, vector<string> &path, string &current, string &start,
                   unordered_map<string, pair<int, vector<string> > > &precursors) {
        if (current == start) {
            result.push_back(path);
            result.back().push_back(start);
            reverse(result.back().begin(), result.back().end());
            return;
        }
        path.push_back(current);
        for (string &pre : precursors[current].second) {
            backtrack(result, path, pre, start, precursors);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return vector<vector<string> >{{start}};
        }
        unordered_map<string, pair<int, vector<string> > > precursors;
        queue<pair<int, string> > q;
        q.push(make_pair(0, start));
        unordered_set<string> visited;
        visited.insert(start);
        int shortestPath = -1;
        while (q.empty() == false) {
            int current = q.front().first;
            string str = q.front().second;
            q.pop();
            if (shortestPath != -1 && current >= shortestPath) {
                break;
            }
            string tmp = str;
            for (int i = 0; i < tmp.size(); ++i) {
                char original = str[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == original) {
                        continue;
                    }
                    tmp[i] = c;
                    if (tmp != end && dict.count(tmp) == 0) {
                        continue;
                    }
                    auto preiter = precursors.find(tmp);
                    if (preiter == precursors.end()) {
                        preiter = precursors.insert(make_pair(tmp, make_pair(current + 1, vector<string>()))).first;
                    } else if (preiter->second.first != current + 1) {
                        continue;
                    }
                    preiter->second.second.push_back(str);
                    if (visited.count(tmp) == 0) {
                        visited.insert(tmp);
                        q.push(make_pair(current + 1, tmp));
                    }
                }
                tmp[i] = original;
            }
        }
        vector<vector<string> > result;
        vector<string> path;
        backtrack(result, path, end, start, precursors);
        return result;
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
    vector<vector<string>> result = s.findLadders(start, end, dict);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
