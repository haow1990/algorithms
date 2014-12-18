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
    void preorder(TreeNode *root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorder(root, result);
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
