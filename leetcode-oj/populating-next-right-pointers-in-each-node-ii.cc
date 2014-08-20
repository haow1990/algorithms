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
        if (root == nullptr) {
            return;
        }
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(nullptr);
        while (q.empty() == false) {
            TreeLinkNode *current = q.front();
            q.pop();
            if (current == nullptr)    continue;
            current->next = q.front();
            if (current->left)  q.push(current->left);
            if (current->right) q.push(current->right);
            if (q.front() == nullptr) {
                q.push(nullptr);
                q.pop();
            }
        }
    }
};

