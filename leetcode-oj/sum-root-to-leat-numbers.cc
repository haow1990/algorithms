#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct task {
    int val;
    TreeNode *node;
    task(TreeNode *n, int v = 0)
        : node(n), val(v)
    {}
};

class Solution {
public:
    int sumNumbers(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        queue<task> q;
        q.push(task(root, 0));
        int sum = 0;
        while (q.empty() == false) {
            int current = q.front().val * 10 + q.front().node->val;
            if (q.front().node->left != NULL) {
                q.push(task(q.front().node->left, current));
            }
            if (q.front().node->right != NULL) {
                q.push(task(q.front().node->right, current));
            }
            if (q.front().node->left == NULL
                    && q.front().node->right == NULL) {
                sum += current;
            }
            q.pop();
        }
        return sum;
    }
};


int main()
{
    TreeNode n1(1), n2(2), n3(3);
    n1.left = &n2;
    n1.right = &n3;
    Solution s;
    cout << s.sumNumbers(&n1) << endl;
    return 0;
}

