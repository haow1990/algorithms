
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root != nullptr) {
            TreeLinkNode dummy(0), *tail = &dummy;
            while (root != nullptr) {
                if (root->left != nullptr) {
                    tail->next = root->left;
                    tail = tail->next;
                }
                if (root->right != nullptr) {
                    tail->next = root->right;
                    tail = tail->next;
                }
                root = root->next;
            }
            root = dummy.next;
        }
    }

};
