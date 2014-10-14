#include <climits>
#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
using namespace std;

tuple<bool, vector<pair<int, int> > > prim(const vector<vector<int> > &graph)
{
    vector<pair<int, int> > result;
    // this is a vertex set starting with only one vertex
    // in each loop, add a vertex not in this nearest to a vertex in this
    vector<bool> vertexIncluded(graph.size(), false);
    vertexIncluded[0] = true;
    vector<int> nearestIncluded(graph.size(), 0);
    for (int i = 1; i < graph.size(); ++i) {
        // pick a nearest vertex
        int v = 0;
        int min = INT_MAX;
        for (int j = 0; j < graph.size(); ++j) {
            if (vertexIncluded[j] == false
                    && graph[j][nearestIncluded[j]] < min) {
                v = j;
                min = graph[j][nearestIncluded[j]];
            }
        }
        if (v == 0) {
            // no reachable nodes left, graph is not connected
            result.clear();
            return make_tuple(false, result);
        }
        result.push_back(make_pair(v, nearestIncluded[v]));
        vertexIncluded[v] = true;
        for (int j = 0; j < graph.size(); ++j) {
            if (vertexIncluded[j] == false
                    && graph[j][v] < graph[j][nearestIncluded[j]]) {
                nearestIncluded[j] = v;
            }
        }
    }
    return make_tuple(true, result);
}

int main(int argc, char **argv)
{
    vector<vector<int> > graph{{0, 8, 1, 6, INT_MAX, INT_MAX},
                               {8, 0, 6, INT_MAX, 3, INT_MAX},
                               {1, 6, 0, 6, 8, 5},
                               {6, INT_MAX, 6, 0, INT_MAX, 2},
                               {INT_MAX, 3, 8, INT_MAX, 0, 8},
                               {INT_MAX, INT_MAX, 5, 2, 8, 0}};
    bool ok;
    vector<pair<int, int> > result;
    tie(ok, result) = prim(graph);
    if (ok) {
        for (auto p : result) {
            cout << p.first << '\t' << p.second << endl;
        }
    } else {
        cout << "not connected\n";
    }
    return 0;
}

