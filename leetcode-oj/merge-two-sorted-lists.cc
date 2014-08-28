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
        ListNode pivot(0);
        ListNode *tail = &pivot;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode *n1 = l1->next;
            ListNode *n2 = l2->next;
            
            tail->next = l1;
            l1->next = l2;
            tail = l2;
            
            l1 = n1;
            l2 = n2;
        }
        if (l1 != nullptr) {
            tail->next = l1;
        } else {
            tail->next = l2;
        }
        return pivot.next;
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
