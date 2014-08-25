#include <limits.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        int left = INT_MAX;
        if (root->left)
            left = minDepth(root->left);
        int right = INT_MAX;
        if (root->right)
            right = minDepth(root->right);
        if (left > right)
            return right + 1;
        else
            return left + 1;
    }
};
