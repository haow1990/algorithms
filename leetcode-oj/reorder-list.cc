#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(ListNode *head)
{
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

ListNode *reverse(ListNode *head)
{
    ListNode *rhead = NULL;
    while (head != NULL) {
        ListNode *next = head->next;       
        head->next = rhead;
        rhead = head;
        head = next;
    }
    return rhead;
}

class Solution {
public:
    void reorderList(ListNode *head) {
        // no change if list contains 0/1/2 nodes
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return;
        }
        // find mid of the list
        ListNode *fast = head, *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *second = slow->next;
        slow->next = NULL;
        second = reverse(second);

        // merge the 2 lists
        while (second != NULL) {
            ListNode *nextHead = head->next;
            ListNode *nextSecond = second->next;
            head->next = second;
            second->next = nextHead;
            head = nextHead;
            second = nextSecond;
        }
    }
};

int main()
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Solution s;
    traverse(&n1);
    s.reorderList(&n1);
    traverse(&n1);
    return 0;
}
