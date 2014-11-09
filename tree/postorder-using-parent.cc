#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right, *parent;
    TreeNode(int vv = 0)
        : val(vv), left(nullptr), right(nullptr), parent(nullptr)
    {}
    
    void setChildren(TreeNode *lc, TreeNode *rc) {
        left = lc;
        right = rc;
        if (left != nullptr) {
            left->parent = this;
        }
        if (right != nullptr) {
            right->parent = this;
        }
    }
};

typedef void (*visit_node_fn)(TreeNode*);

void preorder(TreeNode *root, visit_node_fn fn)
{
    TreeNode *current = root, *last = nullptr;
    while (current != nullptr) {
        if (last == nullptr || last == current->parent) {
            last = current;
            if (current->left != nullptr) {
                current = current->left;
            } else if (current->right != nullptr) {
                current = current->right;
            } else {
                fn(current);
                current = current->parent;
            }
        } else if (last == current->left) {
            last = current;
            if (current->right != nullptr) {
                current = current->right;
            } else {
                fn(current);
                current = current->parent;
            }
        } else { // last == current->right
            fn(current);
            last = current;
            current = current->parent;
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

    preorder(&n3, print_node);
    cout << endl;
}

void test2()
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n4.setChildren(&n2, &n5);
    n2.setChildren(&n1, &n3);

    preorder(&n4, print_node);
    cout << endl;
}

int main(int argc, char **argv)
{
    test1();
    test2();
    return 0;
}

