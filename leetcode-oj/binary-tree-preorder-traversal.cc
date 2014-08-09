#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :  val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        if (root != NULL) {
            nodeStack.push(root);
        }
        while (nodeStack.empty() == false) {
            TreeNode *current = nodeStack.top();
            result.push_back(current->val);
            nodeStack.pop();
            if (current->right != NULL) {
                nodeStack.push(current->right);
            }
            if (current->left != NULL) {
                nodeStack.push(current->left);
            }
        }
        return result;
    }
};

int main()
{
    TreeNode a(2), b(3), c(1), d(4);
    a.left = &b;
    a.right = &d;
    b.right = &c;

    Solution s;
    vector<int> result = s.preorderTraversal(&a);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
