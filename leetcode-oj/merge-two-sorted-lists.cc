#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return dummy.next;
    
    }
};

void traverse(ListNode *head)
{
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    ListNode n11(2);
    ListNode n21(1);
    
    Solution s;
    ListNode *h = s.mergeTwoLists(&n11, &n21);
    traverse(h);
    return 0;
}
