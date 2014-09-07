#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode pivot(0);
        pivot.next = head;

        ListNode *fast = &pivot;
        while (n > 0 && fast->next != nullptr) {
            fast = fast->next;
            --n;
        }
        if (n != 0) {
            return pivot.next;
        }

        ListNode *slow = &pivot;
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return pivot.next;
    }
};

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    ListNode pivot(0);
    ListNode *last = &pivot;
    for (int i = 2; i < argc; ++i) {
        last->next = new ListNode(atoi(argv[i]));
        last = last->next;
    }

    Solution s;
    ListNode *head = s.removeNthFromEnd(pivot.next, n);
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
