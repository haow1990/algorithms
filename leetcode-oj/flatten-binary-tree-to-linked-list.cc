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
    // return my tail
    TreeNode *doFlatten(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        auto mytail = root;
        auto myleft = root->left;
        auto myright = root->right;
        root->left = nullptr;
        root->right = nullptr;
        
        if (myleft != nullptr) {
            auto lefttail = doFlatten(myleft);
            mytail->right = myleft;
            mytail = lefttail;
        }
        
        if (myright != nullptr) {
            auto righttail = doFlatten(myright);
            mytail->right = myright;
            mytail = righttail;
        }
        
        return mytail;
    }
    
    void flatten(TreeNode *root) {
        doFlatten(root);
    }
};
