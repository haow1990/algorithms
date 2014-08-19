#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

void generate(unordered_map<string, pair<int, vector<string>>> &preMap, vector<string> &path, const string &word, vector<vector<string>> &result)
{
    path.push_back(word);
    const vector<string> &pres = preMap[word].second;
    if (pres.size() == 0) {
        result.resize(result.size() + 1);
        result.rbegin()->insert(result.rbegin()->end(), path.rbegin(), path.rend());
    } else {
        for (size_t i = 0; i < pres.size(); ++i) {
            generate(preMap, path, pres[i], result);
        }
    }
    path.pop_back();
}

void addPre(unordered_map<string, pair<int, vector<string>>> &premap, const string &key, const string &pre, int len)
{
    auto iter = premap.find(key);
    if (iter == premap.end()) {
        premap.insert(make_pair(key, make_pair(len, vector<string>()))).first->second.second.push_back(pre);
    } else if (iter->second.first == len) {
        iter->second.second.push_back(pre);
    }
}

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        unordered_map<string, pair<int, vector<string>>> premap;
        q.push(make_pair(start, 1));
        premap.insert(make_pair(start, make_pair(1, vector<string>())));
        while (q.empty() == false) {
            if (q.front().first == end) {
                break;
            }
            string current = q.front().first;
            int len = q.front().second;
            for (size_t i = 0; i < current.size(); ++i) {
                char original = current[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (original == c)  continue;
                    current[i] = c;
                    if (dict.count(current) > 0 || current == end) {
                        addPre(premap, current, q.front().first, len + 1);
                        if (visited.count(current) == 0) {
                            q.push(make_pair(current, len + 1));
                            visited.insert(current);
                        }
                    }
                }
                current[i] = original;
            }

            q.pop();
        }

        vector<vector<string>> result;
        if (start == end || premap.count(end) > 0) {
            vector<string> path;
            generate(premap, path, end, result);
        }
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
