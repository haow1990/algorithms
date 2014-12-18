#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void dfs(TreeNode *root, int current, int &result) {
        current = current * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            result += current;
            return;
        }
        if (root->left != nullptr) {
            dfs(root->left, current, result);
        }
        if (root->right != nullptr) {
            dfs(root->right, current, result);
        }
    }
    
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int result = 0;
        dfs(root, 0, result);
        return result;
    }

};


int main()
{
    TreeNode n1(1), n2(2), n3(3);
    n1.left = &n2;
    n1.right = &n3;
    Solution s;
    cout << s.sumNumbers(&n1) << endl;
    return 0;
}

