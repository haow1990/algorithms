#include <functional>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void morris_inorder(TreeNode *root, std::function<void(TreeNode*)> visit) {
        TreeNode *current = root;
        while (current != nullptr) {
            if (current->left == nullptr) {
                visit(current);
                current = current->right;
            } else {
                // find right most children of left child
                auto tmp = current->left;
                while (tmp->right != nullptr && tmp->right != current) {
                    tmp = tmp->right;
                }
                if (tmp->right == nullptr) {
                    tmp->right = current;
                    current = current->left;
                } else {
                    visit(current);
                    tmp->right = nullptr;
                    current = current->right;
                }
            }
        }
    }
    
    void swap(TreeNode *n1, TreeNode *n2) {
        if (n1 == nullptr || n2 == nullptr) {
            return;
        }
        int tmp = n1->val;
        n1->val = n2->val;
        n2->val = tmp;
    }
    
    void recoverTree(TreeNode *root) {
        TreeNode *first = nullptr, *second = nullptr, *last = nullptr;
        auto fn = [&](TreeNode *current)->void {
            if (last == nullptr) {
                last = current;
                return;
            }
            if (current->val >= last->val) {
                last = current;
                return;
            }
            if (first == nullptr) {
                first = last;
                second = current;
            } else {
                second = current;
            }
            last = current;
        };
        morris_inorder(root, fn);
        swap(first, second);
    }
};

int main()
{
    TreeNode n1(1), n2(2), n3(3);
    n1.left = &n3;
    n3.right = &n2;
    Solution s;
    s.recoverTree(&n1);
    return 0;
}
