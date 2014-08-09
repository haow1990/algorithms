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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        set<TreeNode*> unvisitedSet;
        if (root != NULL) {
            nodeStack.push(root);
            unvisitedSet.insert(root);
        }
        while (nodeStack.empty() == false) {
            TreeNode *current = nodeStack.top();
            set<TreeNode*>::iterator iter = unvisitedSet.find(current);
            if (iter == unvisitedSet.end()) {
                result.push_back(current->val);
                nodeStack.pop();
            } else {
                unvisitedSet.erase(iter);
                if (current->right != NULL) {
                    nodeStack.push(current->right);
                    unvisitedSet.insert(current->right);
                }
                if (current->left != NULL) {
                    nodeStack.push(current->left);
                    unvisitedSet.insert(current->left);
                }
            }
        }
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
