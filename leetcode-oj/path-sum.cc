#include <iostream
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == sum;
        }
        if (root->left != nullptr
                && hasPathSum(root->left, sum - root->val)) {
            return true;
        }
        if (root->right != nullptr
                && hasPathSum(root->right, sum - root->val)) {
            return true;
        }
        return false;
    }
};

int main()
{
}
