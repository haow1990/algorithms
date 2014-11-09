#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int vv = 0)
        : val(vv), left(nullptr), right(nullptr)
    {}
    
    void setChildren(TreeNode *lc, TreeNode *rc) {
        left = lc;
        right = rc;
    }
};

typedef void (*visit_node_fn)(TreeNode*);

void inorder(TreeNode *root, visit_node_fn visit)
{
    auto current = root;
    while (current != nullptr) {
        if (current->left != nullptr) {
            // find right most children of the left child
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
        } else {
            visit(current);
            current = current->right;
        }
    }
}

void print_node(TreeNode *node)
{
    if (node != nullptr) {
        cout << node->val << ' ';
    }
}

void test1()
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n3.setChildren(&n2, &n4);
    n2.setChildren(&n1, nullptr);
    n4.setChildren(nullptr, &n5);

    inorder(&n3, print_node);
    cout << endl;
}

void test2()
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n4.setChildren(&n2, &n5);
    n2.setChildren(&n1, &n3);

    inorder(&n4, print_node);
    cout << endl;
}

int main(int argc, char **argv)
{
    test1();
    test2();
    return 0;
}

