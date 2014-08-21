#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    int height(TreeNode *root)
    {
        if (root == 0) {
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        if (left < 0 || right < 0
                || left > right + 1
                || right > left + 1) {
            return -1;
        }
        if (left > right)
            return left + 1;
        else
            return right + 1;
    }
    bool isBalanced(TreeNode *root) {
        return height(root) >= 0;
    }
};

int main()
{
    TreeNode n1(1), n2(2), n3(3);
    n1.right = &n2;
    n2.right = &n3;

    Solution s;
    cout << s.isBalanced(&n1) << endl;
    return 0;
}
