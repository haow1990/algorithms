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
    RandomListNode *copyRandomList(RandomListNode *head) {
        typedef map<RandomListNode*, RandomListNode*> nmap_t;
        nmap_t nmap;
        nmap[NULL] = NULL;
        for (RandomListNode *p = head; p != NULL; p = p->next) {
            nmap_t::iterator iter = nmap.find(p);
            RandomListNode *pnew;
            if (iter != nmap.end()) {
                pnew = iter->second;
            } else {
                pnew = new RandomListNode(p->label);
                nmap[p] = pnew;
            }
            // copy random node
            if (p->random != NULL) {
                if (nmap.count(p->random) > 0) {
                    pnew->random = nmap[p->random];
                } else {
                    RandomListNode *pnewrandom = new RandomListNode(p->random->label);
                    nmap[p->random] = pnewrandom;
                    pnew->random = pnewrandom;
                }
            }
            // create next node
            if (p->next != NULL) {
                if (nmap.count(p->next) == 0) {
                    RandomListNode *pnewnext = new RandomListNode(p->next->label);
                    nmap[p->next] = pnewnext;
                    pnew->next = pnewnext;
                } else {
                    pnew->next = nmap[p->next];
                }
            }
        }
        return nmap[head];
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
