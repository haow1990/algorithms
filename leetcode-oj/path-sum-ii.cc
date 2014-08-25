#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void doPathSum(vector<vector<int> > &result, TreeNode *node, int sum, vector<int> &path)
    {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == node->val) {
                result.push_back(path);
            }
        } else {
            if (node->left != nullptr)
                doPathSum(result, node->left, sum - node->val, path);
            if (node->right != nullptr)
                doPathSum(result, node->right, sum - node->val, path);
        }
        path.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;       
        vector<int> path;
        if (root != nullptr) {
            doPathSum(result, root, sum, path);
        }
        return result;
    }
};
