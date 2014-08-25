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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode pivot(0);
        pivot.next = head;
        head = &pivot;
        while (head->next != nullptr) {
            if (head->next->next != nullptr &&
                    head->next->val == head->next->next->val) {
                int val = head->next->val;
                while (head->next != nullptr && head->next->val == val) {
                    ListNode *p = head->next;
                    head->next = p->next;
                    delete p;
                }
            } else {
                head = head->next;
            }
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
    ListNode pivot(0);
    ListNode *head = &pivot;
    for (int i = 1; i < argc; ++i)
    {
        ListNode *p = new ListNode(atoi(argv[i]));
        head->next = p;
        head = p;
    }
    traverse(pivot.next);
    Solution s;
    traverse(s.deleteDuplicates(pivot.next));
    cout << endl;
    return 0;
}
