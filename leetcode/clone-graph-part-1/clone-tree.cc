#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

typedef long ssize_t;

struct Node {
	int data;
	vector<Node*> neighbors;

	Node(int dataval = 0)
		: data(dataval)
	{}
};

void depthfirst_traverse_before(Node *root)
{
	if (root != NULL) {
		cout << root->data << ' ';

		vector<Node*> &neighbors = root->neighbors;
		for (size_t i = 0; i < neighbors.size(); ++i) {
			depthfirst_traverse_before(neighbors[i]);
		}
	}
}

void depthfirst_userstack_traverse_before(Node *root)
{
	stack<Node*> stk;
	if (root != NULL) {
		stk.push(root);
	}
	while (stk.empty() == false) {
		Node *node = stk.top();
		stk.pop();

		cout << node->data << ' ';
		for (ssize_t i = (long)node->neighbors.size() - 1; i >= 0; --i) {
			stk.push(node->neighbors[i]);
		}
	}
}

void depthfirst_traverse_after(Node *root)
{
	if (root != NULL) {
		vector<Node*> &neighbors = root->neighbors;
		for (size_t i = 0; i < root->neighbors.size(); ++i) {
			depthfirst_traverse_after(neighbors[i]);
		}

		cout << root->data << ' ';
	}
}

void depthfirst_userstack_traverse_after(Node *root)
{
	typedef pair<Node*, bool> VisitHistory; // node, bool means if child extracted
	stack<VisitHistory> stk;
	if (root != NULL) {
		stk.push(VisitHistory(root, false));
		while (stk.empty() == false) {
			Node *node = stk.top().first;
			if (stk.top().second == false) {
				stk.top().second = true;
				for (ssize_t i = (long)node->neighbors.size() - 1; i >= 0; --i) {
					stk.push(VisitHistory(node->neighbors[i], false));
				}
			} else {
				cout << node->data << ' ';
				stk.pop();
			}
		}
	}
}

void breadthfirst_traverse(Node *root)
{
	queue<Node*> queue;
	if (root != NULL) {
		queue.push(root);
	}

	while (queue.empty() == false) {
		Node *node = queue.front();
		queue.pop();

		cout << node->data << ' ';
		vector<Node*> &neighbors = node->neighbors;
		for (size_t i = 0; i < neighbors.size(); ++i) {
			if (neighbors[i] != NULL) {
				queue.push(neighbors[i]);
			}
		}
	}
}

/**
 * origin and target should not be NULL
 */
void depthfirst_clone_onenode(Node *origin, Node *target)
{
	target->data = origin->data;
	target->neighbors.reserve(origin->neighbors.size());
	for (size_t i = 0; i < origin->neighbors.size(); ++i) {
		Node *child = new Node();
		depthfirst_clone_onenode(origin->neighbors[i], child);
		target->neighbors.push_back(child);
	}
}

struct Node *depthfirst_clone(struct Node *root)
{
	if (root != NULL) {
		Node *result = new Node();
		depthfirst_clone_onenode(root, result);
		return result;
	} else {
		return NULL;
	}
}

typedef pair<Node*, Node*> NodePtrPair;

struct Node *breadthfirst_clone(struct Node *root)
{
	if (root != NULL) {
		queue<NodePtrPair> nodesToClone;
		Node *result = new Node();
		nodesToClone.push(NodePtrPair(root, result));
		while (nodesToClone.empty() == false) {
			Node *origin = nodesToClone.front().first;
			Node *target = nodesToClone.front().second;
			nodesToClone.pop();

			target->data = origin->data;
			for (size_t i = 0; i < origin->neighbors.size(); ++i) {
				if (origin->neighbors[i] != NULL) {
					Node *child = new Node();
					nodesToClone.push(NodePtrPair(origin->neighbors[i], child));
					target->neighbors.push_back(child);
				}
			}
		}
		return result;
	} else {
		return NULL;
	}
}

void display_tree(Node *root)
{
	cout << "depthfirst_traverse_before:";
	depthfirst_traverse_before(root);
	cout << endl;

	cout << "depthfirst_userstack_traverse_before:";
	depthfirst_userstack_traverse_before(root);
	cout << endl;

	cout << "depthfirst_traverse_after: ";
	depthfirst_traverse_after(root);
	cout << endl;

	cout << "depthfirst_userstack_traverse_after: ";
	depthfirst_userstack_traverse_after(root);
	cout << endl;

	cout << "breadthfirst_traverse: ";
	breadthfirst_traverse(root);
	cout << endl;
}

int main()
{
	Node *root = new Node(1);
	root->neighbors.push_back(new Node(2));
	root->neighbors.push_back(new Node(3));
	root->neighbors.push_back(new Node(4));
	root->neighbors[2]->neighbors.push_back(new Node(5));
	root->neighbors[2]->neighbors.push_back(new Node(6));

	cout << "original tree\n";
	display_tree(root);

	Node *depthcopy = depthfirst_clone(root);
	cout << "depthfirst_clone\n";
	display_tree(depthcopy);

	Node *breadthcopy = breadthfirst_clone(root);
	cout << "breadthfirst_clone\n";
	display_tree(breadthcopy);

	return 0;

}













