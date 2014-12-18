#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *n1, ListNode *n2) {
            return n1->val > n2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for (ListNode *node : lists) {
            if (node != nullptr) {
                q.push(node);
            }
        }
        ListNode dummy(0), *tail = &dummy;
        while (q.empty() == false) {
            tail->next = q.top();
            tail = tail->next;
            q.pop();
            if (tail->next != nullptr) {
                q.push(tail->next);
            }
        }
        tail->next = nullptr;
        return dummy.next;
    
    }
};

int main(int argc, char **argv)
{
    return 0;
}
