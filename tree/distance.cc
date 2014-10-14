#include <iostream>
#include <utility>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int val)
        : value(val), left(nullptr), right(nullptr)
    {}
};

pair<int, int> traverse(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    if (root == nullptr) {
        return make_pair(-1, -1);
    }
    auto left = traverse(root->left, n1, n2);
    if (left.first >= 0 && left.second >= 0) {
        return left;
    }
    auto right = traverse(root->right, n1, n2);
    if (right.first >= 0 && right.second >= 0) {
        return right;
    }

    int d1 = -1;
    int d2 = -1;
    if (root == n1) {
        d1 = 0;
    }
    if (root == n2) {
        d2 = 0;
    }
    if (left.first >= 0) {
        d1 = left.first + 1;
    } else if (right.first >= 0) {
        d1 = right.first + 1;
    }
    if (left.second >= 0) {
        d2 = left.second + 1;
    } else if (right.second >= 0) {
        d2 = right.second + 1;
    }
    return make_pair(d1, d2);
}

int distance(TreeNode *root, TreeNode *n1, TreeNode *n2)
{
    if (n1 == n2 || n1 == nullptr || n2 == nullptr) {
        return 0;
    }
    auto result = traverse(root, n1, n2);
    if (result.second < 0 || result.second < 0) {
        return -1;
    } else {
        return result.first + result.second;
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

    cout << distance(&n1, &n1, &n1) << endl;

    return 0;
}

