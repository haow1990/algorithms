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
        ListNode dummy1(0), dummy2(0);
        auto tail1 = &dummy1;
        auto tail2 = &dummy2;
        while (head != nullptr) {
            if (head->val < x) {
                tail1->next = head;
                tail1 = head;
            } else {
                tail2->next = head;
                tail2 = head;
            }
            head = head->next;
        }
        tail1->next = dummy2.next;
        tail2->next = nullptr;
        return dummy1.next;
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
