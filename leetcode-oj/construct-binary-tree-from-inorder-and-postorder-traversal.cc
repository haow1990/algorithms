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
    TreeNode *construct(vector<int> &inorder, size_t &i, vector<int> &postorder, size_t &j)
    {
        if (j >= inorder.size())
            return nullptr;
        TreeNode *node = new TreeNode(postorder[j]);
        visited.insert(postorder[j]);
        --j;
        if (visited.count(inorder[i]) == 0) {
            node->right = construct(inorder, i, postorder, j);
        } else {
            --i;
        }
        if (visited.count(inorder[i]) == 0) {
            node->left = construct(inorder, i, postorder, j);
        } else {
            --i;
        }
        return node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        visited.clear();
        size_t i = inorder.size() - 1, j = postorder.size() - 1;
        return construct(inorder, i, postorder, j);
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

void postorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

int main(int argc, char **argv)
{
    vector<int> pst{1,4,3,2};//{7,-10,-4,3,-1,2,-8,11};
    vector<int> mid{1,2,3,4};//{-4,-10,3,-1,7,11,-8,2};
    Solution s;
    TreeNode *root = s.buildTree(mid, pst);
    cout << "pst: ";
    postorder(root);
    cout << "\n";
    cout << "mid: ";
    midorder(root);
    cout << "\n";
    return 0;
}




