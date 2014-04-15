#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
using namespace std;

struct Node {
	int data;
	vector<Node*> neighbors;
	Node(int dataval = 0)
		: data(dataval)
	{}
};

void traverse_depthfirst(Node *root)
{
	if (root == NULL) {
		return;
	}

	stack<Node*> stk;
	stk.push(root);
	set<Node*> visitHistory;
	visitHistory.push(root);
	while (stk.empty() == false) {
		Node *node = stk.top();
		stk.pop();

		// visit
		cout << stk.top().data << ' ';

		// children
		for (vector<Node*>::reverse_iterator iter = node->neighbors.rbegin();
				iter != node->neighbors.rend(); ++iter) {
			Node *child = *iter;
			if (visitHistory.count(child) == 0) {
				visitHistory.insert(child);
				stk.push(child);
			}
		}
	}
	cout << endl;
}

int main()
{
	Node a(1), b(2), c(3), d(4), e(5);
	
	return 0;
}











