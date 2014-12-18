#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverse(ListNode *head) {
        ListNode *res = nullptr;
        while (head != nullptr) {
            auto next = head->next;
            head->next = res;
            res = head;
            head = next;
        }
        return res;
    }
    
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        
        auto fast = head;
        auto slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto p = reverse(slow->next);
        slow->next = nullptr;
        auto tail = head;
        while (p != nullptr) {
            auto nextp = p->next;
            auto nextt = tail->next;
            p->next = nextt;
            tail->next = p;
            tail = nextt;
            p = nextp;
        }
    }

};

int main()
{
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Solution s;
    traverse(&n1);
    s.reorderList(&n1);
    traverse(&n1);
    return 0;
}
