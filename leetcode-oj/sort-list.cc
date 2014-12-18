#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        auto fast = head;
        auto slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto second = slow->next;
        slow->next = nullptr;
        auto first = sortList(head);
        second = sortList(second);
        ListNode dummy(0), *tail = &dummy;
        while (first != nullptr && second != nullptr) {
            if (first->val < second->val) {
                tail->next = first;
                tail = first;
                first = first->next;
            } else {
                tail->next = second;
                tail = second;
                second = second->next;
            }
        }
        if (first != nullptr) {
            tail->next = first;
        } else {
            tail->next = second;
        }
        return dummy.next;
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
    head = mergeSort(head);
    traverseList(head);

    return 0;
}


