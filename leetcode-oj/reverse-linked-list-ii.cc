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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode pivot(0);
        pivot.next = head;
        head = &pivot;
        
        int current = 1;
        while (current < m) {
            head = head->next;
            ++current;
        }

        ListNode *p = head->next;
        ListNode *reverseEnd = head->next;
        ListNode *reverseHead = nullptr;
        while (current <= n) {
            ListNode *q = p->next;
            p->next = reverseHead;
            reverseHead = p;
            p = q;
            ++current;
        }
        head->next = reverseHead;
        reverseEnd->next = p;
        return pivot.next;
    }
};

void traverse(ListNode *head)
{
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main(int argc, char **argv)
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    //n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Solution s;
    ListNode *head = s.reverseBetween(&n1, atoi(argv[1]), atoi(argv[2]));
    traverse(head);
    return 0;
}


