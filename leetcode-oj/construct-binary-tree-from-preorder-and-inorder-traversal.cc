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
    unordered_set<int> visited;
    TreeNode *construct(vector<int> &preorder, size_t &i, vector<int> &inorder, size_t &j)
    {
        if (i >= preorder.size())
            return nullptr;
        TreeNode *node = new TreeNode(preorder[i]);
        visited.insert(preorder[i]);
        ++i;
        if (visited.count(inorder[j]) == 0) {
            node->left = construct(preorder, i, inorder, j);
        } else {
            ++j;
        }
        if (visited.count(inorder[j]) == 0) {
            node->right = construct(preorder, i, inorder, j);
        } else {
            ++j;
        }
        return node;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        visited.clear();
        size_t i = 0, j = 0;
        return construct(preorder, i, inorder, j);
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




