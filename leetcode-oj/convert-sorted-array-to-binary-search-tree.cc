#include <cstdlib>
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
    TreeNode *convert(const vector<int> &num, size_t start, size_t end)
    {
        if (start >= end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = convert(num, start, mid);
        root->right = convert(num, mid+1, end);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return convert(num, 0, num.size());
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
    vector<int> num;
    num.reserve(argc - 1);
    for (int i = 1; i < argc; ++i) {
        num.push_back(atoi(argv[i]));
    }
    Solution s;
    TreeNode *root = s.sortedArrayToBST(num);
    cout << "pre: ";
    preorder(root);
    cout << "\n";
    cout << "mid: ";
    midorder(root);
    cout << "\n";
    return 0;
}
