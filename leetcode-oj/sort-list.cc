#include <cstdlib>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void swap(ListNode *node1, ListNode *node2)
{
    int tmp = node1->val;
    node1->val = node2->val;
    node2->val = tmp;
}

ListNode *merge(ListNode *head1, ListNode *head2)
{
    if (head1 == NULL) {
        return head1;
    }
    if (head2 == NULL) {
        return head2;
    }
    ListNode *ret;
    if (head1->val < head2->val) {
        ret = head1;
        head1 = head1->next;
    } else {
        ret = head2;
        head2 = head2->next;
    }
    ListNode *tail = ret;
    while (head1 != NULL && head2 != NULL) {
        if (head1->val < head2->val) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if (head1 == NULL) {
        tail->next = head2;
    } else {
        tail->next = head1;
    }
    return ret;
}

ListNode *mergeSort(ListNode *head)
{
    if (head == NULL || head ->next == NULL) {
        return head;
    }
    // find middle of the list
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *head1 = head;
    ListNode *head2 = slow->next;
    slow->next = NULL;

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    return merge(head1, head2);
}

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
        return mergeSort(head);
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


