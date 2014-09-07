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
    ListNode *swapPairs(ListNode *head) {
        ListNode pivot(0);
        pivot.next = head;
        ListNode *last = &pivot;
        while (last->next != nullptr && last->next->next != nullptr) {
            ListNode *p1 = last->next;
            ListNode *p2 = p1->next;
            ListNode *p3 = p2->next;
            last->next = p2;
            p2->next = p1;
            p1->next = p3;
            last = p1;
        }
        return pivot.next;
    }
};

int main(int argc, char **argv)
{
    ListNode pivot(0);
    ListNode *last = &pivot;
    for (int i = 1; i < argc; ++i) {
        last->next = new ListNode(atoi(argv[i]));
        last = last->next;
    }

    Solution s;
    ListNode *head = s.swapPairs(pivot.next);
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
