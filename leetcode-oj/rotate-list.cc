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
    ListNode *rotateRight(ListNode *head, int k) {
        if (k <= 0 || head == nullptr) {
            return head;
        }

        ListNode *p1, *p2;
        p1 = head;
        p2 = head;
        while (k > 0 && p2->next != nullptr) {
            p2 = p2->next;
            --k;
        }
        if (k > 0) {
            return head;
        }
        
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = head;
        head = p1->next;
        p1->next = nullptr;
        return head;
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
    int k = atoi(argv[1]);
    ListNode pivot(0);
    ListNode *tail = &pivot;
    for (int i = 2; i < argc; ++i) {
        tail->next = new ListNode(atoi(argv[i]));
        tail = tail->next;
    }
    Solution s;
    ListNode *head = s.rotateRight(pivot.next, k);
    traverse(head);
    return 0;
}

