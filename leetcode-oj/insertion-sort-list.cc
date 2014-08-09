#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode pivotHead(0);
        ListNode *p1 = head;
        while (p1 != NULL) {
            ListNode *p2 = &pivotHead;
            ListNode *nextP1 = p1->next;
            while (p2->next != NULL && p2->next->val < p1->val) {
                p2 = p2->next;
            }
            p1->next = p2->next;
            p2->next = p1;
            p1 = nextP1;
        }
        return pivotHead.next;
    }
};

void traverseList(ListNode *head)
{
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    ListNode *head = NULL, *tail;
    for (int i = 1; i < argc; ++i) {
        if (head == NULL) {
            head = tail = new ListNode(atoi(argv[i]));
        } else {
            tail->next = new ListNode(atoi(argv[i]));
            tail = tail->next;
        }
    }

    traverseList(head);
    Solution s;
    head = s.insertionSortList(head);
    traverseList(head);

    return 0;
}
