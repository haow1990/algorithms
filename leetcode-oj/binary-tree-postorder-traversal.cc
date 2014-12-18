#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :  val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void post(TreeNode *root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        post(root->left, result);
        post(root->right, result);
        result.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        post(root, result);
        return result;
    }
};

int main()
{
    TreeNode a(2), b(3), c(1);
    a.left = &b;
    b.right = &c;

    Solution s;
    vector<int> result = s.postorderTraversal(&a);
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;
    return 0;
}
