
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root, TreeLinkNode *next)
    {
        if (root == NULL) {
            return;
        }
        if (root->left) {
            root->left->next = root->right;
            connect(root->left, root->right);
        }
        if (root->right && next) {
            root->right->next = next->left;
        }
        if (root->right) {
            connect(root->right, root->right->next);
        }
    }
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
};
