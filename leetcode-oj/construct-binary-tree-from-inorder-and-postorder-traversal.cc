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
    TreeNode *build(vector<int> &inorder, int ii, int ij, vector<int> &post, int &pi, unordered_map<int, int> &idxmap) {
        if (ii > ij || pi < 0) {
            return nullptr;
        }
        int val = post[pi--];
        int idx = idxmap[val];
        auto root = new TreeNode(val);
        root->right = build(inorder, idx + 1, ij, post, pi, idxmap);
        root->left = build(inorder, ii, idx - 1, post, pi, idxmap);
        return root;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> idxmap;
        for (int i = 0; i < inorder.size(); ++i) {
            idxmap[inorder[i]] = i;
        }
        int pi = postorder.size() - 1;
        return build(inorder, 0, inorder.size() - 1, postorder, pi, idxmap);
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




