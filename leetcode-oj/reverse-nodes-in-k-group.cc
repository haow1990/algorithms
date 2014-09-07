#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) {
            return head;
        }
        ListNode pivot(0);
        pivot.next = head;
        ListNode *last = &pivot;
        vector<ListNode*> nodes(k);
        while (last->next != nullptr) {
            int i = 0;
            ListNode *p = last->next;
            while (i < k && p != nullptr) {
                nodes[i++] = p;
                p = p->next;
            }
            if (i != k) {
                break;
            }
            last->next = nodes.back();
            for (int i = k - 1; i > 0; --i) {
                nodes[i]->next = nodes[i-1];
            }
            nodes.front()->next = p;
            last = nodes.front();
        }
        return pivot.next;
    }
};

int main(int argc, char **argv)
{
    int k = atoi(argv[1]);
    ListNode pivot(0);
    ListNode *last = &pivot;
    for (int i = 2; i < argc; ++i) {
        last->next = new ListNode(atoi(argv[i]));
        last = last->next;
    }

    Solution s;
    ListNode *head = s.reverseKGroup(pivot.next, k);
    while (head != nullptr) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
