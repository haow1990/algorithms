#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode pivot(0);
        ListNode *firstHalfTail = &pivot;
        ListNode secondHalfHead(0);
        ListNode *secondHalfTail = &secondHalfHead;

        while (head != nullptr) {
            if (head->val < x) {
                firstHalfTail->next = head;
                head = head->next;
                firstHalfTail = firstHalfTail->next;
                firstHalfTail->next = nullptr;
            } else {
                secondHalfTail->next = head;
                head = head->next;
                secondHalfTail = secondHalfTail->next;
                secondHalfTail->next = nullptr;
            }
        }

        firstHalfTail->next = secondHalfHead.next;
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
    int x = atoi(argv[1]);
    ListNode pivot(0);
    ListNode *tail = &pivot;
    for (int i = 2; i < argc; ++i) {
        tail->next = new ListNode(atoi(argv[i]));
        tail = tail->next;
    }

    ListNode *head = pivot.next;
    traverse(head);
    Solution s;
    head = s.partition(head, x);
    traverse(head);

    return 0;
}
