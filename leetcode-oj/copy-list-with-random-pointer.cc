#include <iostream>
#include <map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *getOrCreate(RandomListNode *original, unordered_map<RandomListNode*, RandomListNode*> &nmap) {
        if (original == nullptr) {
            return nullptr;
        }
        auto iter = nmap.insert(make_pair(original, nullptr)).first;
        if (iter->second == nullptr) {
            iter->second = new RandomListNode(original->label);
        }
        return iter->second;
    }
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode dummy(0), *tail = &dummy;
        unordered_map<RandomListNode*, RandomListNode*> nmap;
        while (head != nullptr) {
            tail = tail->next = getOrCreate(head, nmap);
            tail->random = getOrCreate(head->random, nmap);
            head = head->next;
        }
        return dummy.next;
    }

};

int main()
{
    RandomListNode n1(1), n2(2), n3(3), n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    n1.random = &n3;
    n2.random = &n1;

    Solution s;
    RandomListNode *pnew = s.copyRandomList(&n1);
    while (pnew != NULL) {
        cout << pnew->label;
        if (pnew->random != NULL) {
            cout << ' ' << pnew->random->label;
        }
        cout << endl;
        pnew = pnew->next;
    }

    return 0;
}
