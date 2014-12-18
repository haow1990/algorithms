#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *build(vector<int> &pre, int &pi, vector<int> &inorder, int ii, int ij, unordered_map<int, int> &idxmap) {
        if (pi >= pre.size() || ii > ij) {
            return nullptr;
        }
        int val = pre[pi++];
        int idx = idxmap[val];
        TreeNode *root = new TreeNode(val);
        root->left = build(pre, pi, inorder, ii, idx - 1, idxmap);
        root->right = build(pre, pi, inorder, idx + 1, ij, idxmap);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> idxmap;
        for (int i = 0; i < inorder.size(); ++i) {
            idxmap[inorder[i]] = i;
        }
        int pi = 0;
        return build(preorder, pi, inorder, 0, inorder.size() - 1, idxmap);
    }
};

void midorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    midorder(root->left);
    cout << root->val << ' ';
    midorder(root->right);
}

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

int main(int argc, char **argv)
{
    vector<int> pre{7,-10,-4,3,-1,2,-8,11};
    vector<int> mid{-4,-10,3,-1,7,11,-8,2};
    Solution s;
    TreeNode *root = s.buildTree(pre, mid);
    cout << "pre: ";
    preorder(root);
    cout << "\n";
    cout << "mid: ";
    midorder(root);
    cout << "\n";
    return 0;
}




