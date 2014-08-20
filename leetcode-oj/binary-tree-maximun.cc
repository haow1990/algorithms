#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    int max;
public:
    int maxPathSum(TreeNode *root) {
        max = INT_MIN;
        if (root == NULL)
            return 0;
        doMaxPathSum(root);
        return max;
    }

    int doMaxPathSum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int lmax = doMaxPathSum(root->left);
        int rmax = doMaxPathSum(root->right);
        if (root->left && lmax > max)
            max = lmax;
        if (root->right && rmax > max)
            max = rmax;
        if (root->val > max)
            max = root->val;
        if (lmax + rmax + root->val > max) {
            max = lmax + rmax + root->val;
        }
        int mymax = root->val;
        int maxchild = lmax;
        if (maxchild < rmax) {
            maxchild = rmax;
        }
        if (maxchild > 0) {
            mymax = mymax + maxchild;
        }
        if (mymax > max) {
            max = mymax;
        }
        return mymax;
    }
};

int main()
{
    TreeNode n1(-1), n2(2), n3(3);
    n1.left = &n2;
    n1.right = &n3;

    Solution s;
    cout << s.maxPathSum(&n1) << endl;
    return 0;
}
