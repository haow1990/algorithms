#include <iostream>
#include <tuple>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int val)
        : value(val), left(nullptr), right(nullptr)
    {}
};

tuple<bool, bool, TreeNode*> traversal(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    if (root == nullptr) {
        return make_tuple(false, false, nullptr);
    }
    bool isN1 = (root == n1) ? true : false;
    bool isN2 = (root == n2) ? true : false;
    auto left = traversal(root->left, n1, n2);
    auto right = traversal(root->right, n1, n2);
    if (get<0>(left) && get<1>(left)) {
        return left;
    }
    if (get<0>(right) && get<1>(right)) {
        return right;
    }
    return make_tuple(isN1 || get<0>(left) || get<0>(right),
                      isN2 || get<1>(left) || get<1>(right),
                      root);
}

TreeNode *getCommonFather(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    if (n1 == n2) {
        return n1;
    }
    if (n1 == nullptr) {
        return n2;
    }
    if (n2 == nullptr) {
        return n1;
    }
    auto result = traversal(root, n1, n2);
    if (get<0>(result) && get<1>(result)) {
        return get<2>(result);
    } else {
        return nullptr;
    }
}

int main(int argc, char **argv)
{
    TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7), n8(8);
    //               1
    //         /          \
    //        2            3
    //     /      \         \
    //    4       5          6
    //          /   \
    //         7     8
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    n5.left = &n7;
    n5.right = &n8;

    TreeNode *result = getCommonFather(&n1, &n4, &n6);
    if (result == nullptr) {
        cout << "(nil)\n";
    } else {
        cout << result->value << endl;
    }

    return 0;
}

