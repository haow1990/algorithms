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
    TreeNode* dup(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto re = new TreeNode(root->val);
        re->left = dup(root->left);
        re->right = dup(root->right);
        return re;
    }
    
    void destroy(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        destroy(root->left);
        destroy(root->right);
        delete root;
    }
    
    // gen trees i..j inclusive
    vector<TreeNode*> generate(int i, int j) {
        if (i > j) {
            return vector<TreeNode*>{nullptr};
        }
        vector<TreeNode*> result;
        for (int k = i; k <= j; ++k) {
            auto left = generate(i, k - 1);
            auto right = generate(k + 1, j);
            for (TreeNode *r1 : left) {
                for (TreeNode *r2 : right) {
                    auto r = new TreeNode(k);
                    r->left = dup(r1);
                    r->right = dup(r2);
                    result.push_back(r);
                }
            }
            for (auto r : left) {
                destroy(r);
            }
            for (auto r : right) {
                destroy(r);
            }
        }
        return result;
    }
    
    vector<TreeNode *> generateTrees(int n) {
        return generate(1, n);
    }
};
