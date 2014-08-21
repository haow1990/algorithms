#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void doFlatten(TreeNode *root, vector<TreeNode*> &vec)
    {
        vec.push_back(root);
        if (root->left != nullptr)
            doFlatten(root->left, vec);
        if (root->right != nullptr)
            doFlatten(root->right, vec);
    }
    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;
        vector<TreeNode*> vec;
        doFlatten(root, vec);
        vec.push_back(nullptr);
        for (size_t i = 0; i < vec.size() - 1; ++i) {
            vec[i]->left = nullptr;
            vec[i]->right = vec[i+1];
        }
    }
};
