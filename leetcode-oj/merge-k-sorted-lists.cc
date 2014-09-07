#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator()(ListNode *p1, ListNode *p2) const {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (ListNode *node : lists) {
            if (node != nullptr) {
                q.push(node);
            }
        }
        ListNode pivot(0);
        ListNode *last = &pivot;
        while (q.empty() == false) {
            last->next = q.top();
            last = q.top();
            q.pop();
            if (last->next != nullptr) {
                q.push(last->next);
            }
        }
        last->next = nullptr;
        return pivot.next;
    }
};

int main(int argc, char **argv)
{
    return 0;
}
