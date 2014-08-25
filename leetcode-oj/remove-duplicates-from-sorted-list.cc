/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        while (head->next != nullptr) {
            ListNode *next = head->next;
            if (next->val == head->val) {
                head->next = next->next;
                delete next;
            } else {
                head = next;
            }
        }
        return head;
    }
