#include <queue>
using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root != nullptr) {
            TreeLinkNode dummyLeftMost(0);
            TreeLinkNode *nextLayerIter = &dummyLeftMost;
            TreeLinkNode *currentLayerIter = root;
            while (currentLayerIter != nullptr) {
                if (currentLayerIter->left != nullptr) {
                    nextLayerIter->next = currentLayerIter->left;
                    nextLayerIter = currentLayerIter->left;
                }
                if (currentLayerIter->right != nullptr) {
                    nextLayerIter->next = currentLayerIter->right;
                    nextLayerIter = currentLayerIter->right;
                }
                currentLayerIter = currentLayerIter->next;
            }
            root = dummyLeftMost.next;
        }
    

    }
};

