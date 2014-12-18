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
    int max(int x, int y) {
        return x > y ? x : y;
    }
    
    int max(int x, int y, int z) {
        return x > y ? max(x, z) : max(y, z);
    }
    
    int post(TreeNode *root, int &res) {
        if (root == nullptr) {
            return 0;
        }
        int left = post(root->left, res);
        int right = post(root->right, res);
        int thispath = root->val + max(left, 0) + max(right, 0);
        res = max(res, thispath);
        return root->val + max(left, right, 0);
    }
    
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else {
            int res = root->val;
            post(root, res);
            return res;
        }
    }
};
