
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        vector<int> nums;
        while (head != null) {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
};
