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
    bool valid(TreeNode *root, int lower, int upper) {
        if (root == nullptr) {
            return true;
        }
        if (root->val < lower || root->val > upper) {
            return false;
        }
        if (root->val == INT_MIN && root->left != nullptr) {
            return false;
        }
        if (root->val == INT_MAX && root->right != nullptr) {
            return false;
        }
        return valid(root->left, lower, root->val - 1)
               && valid(root->right, root->val + 1, upper);
    }
    
    bool isValidBST(TreeNode *root) {
        return valid(root, INT_MIN, INT_MAX);
    }
};
