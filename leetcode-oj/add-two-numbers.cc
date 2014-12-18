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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            int x = l1->val + l2->val + carry;
            tail->next = new ListNode(x % 10);
            tail = tail->next;
            carry = x / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        auto remaining = (l1 == nullptr) ? l2 : l1;
        while (remaining != nullptr) {
            int x = remaining->val + carry;
            tail->next = new ListNode(x % 10);
            tail = tail->next;
            carry = x / 10;
            remaining = remaining->next;
        }
        if (carry != 0) {
            tail->next = new ListNode(carry);
        }
        return dummy.next;
    
    }
};

void print(ListNode *head)
{
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    ListNode p1(0), p2(0);
    ListNode *tail = &p1;
    do {
        tail->next = new ListNode(n1 % 10);
        tail = tail->next;
        n1 = n1 / 10;
    } while (n1 != 0);
    tail = &p2;
    do {
        tail->next = new ListNode(n2 % 10);
        tail = tail->next;
        n2 = n2 / 10;
    } while (n2 != 0);

    print(p1.next);
    print(p2.next);

    Solution s;
    ListNode *result = s.addTwoNumbers(p1.next, p2.next);
    print(result);
    return 0;
}
