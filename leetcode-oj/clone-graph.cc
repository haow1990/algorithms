#include <cstdlib>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode* doCloneGraph(UndirectedGraphNode *node, map<UndirectedGraphNode*, UndirectedGraphNode*> &nodemap)
{
    if (node == NULL) {
        return NULL;
    }
    map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator
        iter = nodemap.find(node);
    if (iter != nodemap.end()) {
        return iter->second;
    }
    
    UndirectedGraphNode *pnew = new UndirectedGraphNode(node->label);
    nodemap[node] = pnew;
    pnew->neighbors.reserve(node->neighbors.size());
    for (size_t i = 0; i < node->neighbors.size(); ++i) {
        pnew->neighbors.push_back(doCloneGraph(node->neighbors[i], nodemap));
    }
    return pnew;
}

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
            return NULL;
        }
        map<UndirectedGraphNode*, UndirectedGraphNode*> nodemap;
        return doCloneGraph(node, nodemap);
    }
};

int main()
{
    UndirectedGraphNode node(-1);
    Solution s;
    s.cloneGraph(&node);
    return 0;
}
