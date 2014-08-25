/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *first, *second, *last;
    void recover(TreeNode *root)
    {
        if (root == nullptr)
            return;
        recover(root->left);
        if (last != nullptr) {
            if (first == nullptr) {
                if (last->val > root->val) {
                    first = last;
                    second = root;
                }
            } else {
                if (first->val > root->val) {
                    second = root;
                }
            }
        }
        last = root;
        recover(root->right);
    }

    void recoverTree(TreeNode *root) {
        first = nullptr;
        second = nullptr;
        last = nullptr;
        recover(root);
        if (first && second) {
            int tmp = first->val;
            first->val = second->val
            second->val = tmp;
        }
    }
};
