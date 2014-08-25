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
    bool isSym(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr)
            return true;
        return isSym(root->left, root->right);
    }
};
