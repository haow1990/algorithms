#include <queue>
using namespace std;

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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        result.resize(1);
        while (q.empty() == false) {
            TreeNode *current = q.front();
            q.pop();
            result.back().push_back(current->val);
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
            if (q.front() == nullptr) {
                q.pop();
                if (q.empty() == false) {
                    q.push(nullptr);
                    resule.resize(result.size() + 1);
                }
            }
        }
    }
};
