#include <climits>
#include <cstdio>

struct Node {
	int nid;
	int prevId;
	int distance;
	bool included;
};

static inline void swap(int nodes[], int i, int j)
{
	int tmp = nodes[i];
	nodes[i] = nodes[j];
	nodes[j] = tmp;
}

static void siftUp(Node nodes[], int nheap[], int i)
{
	int parent;
	while (i != 0) {
		parent = (i - 1) / 2;
		if (nodes[nheap[i]].distance < nodes[nheap[parent]].distance) {
			swap(nheap, i, parent);
			i = parent;
		} else {
			break;
		}
	}
}

static void makeHeap(Node nodes[], int nheap[], int len)
{
	int i;
	for (i = 1; i < len; ++i) {
		siftUp(nodes, nheap, i);
	}
}

// INT_MAX means unreachable
int dijkstra(int *graph, const int n, int from, int to)
{
	Node nodes[n];
	for (int i = 0; i < n; ++i) {
		nodes[i].nid = i;
		nodes[i].prevId = -1;
		nodes[i].distance = INT_MAX;
		nodes[i].included = false;
	}
	nodes[from].distance = 0;

	int nheap[n];
	for (int i = 0; i < n; ++i) {
		nheap[i] = i;
	}
	if (from != 0) {
		swap(nheap, from, 0);
	}

	int curlen = n;
	while (nodes[to].included == false) {
		if (nodes[nheap[0]].distance == INT_MAX) {
			break;
		}

		int u = nheap[0];
		nodes[u].included = true;
		nheap[0] = nheap[curlen - 1];
		--curlen;

		for (int v = 0; v < n; ++v) {
			int lenUV = *(graph + u * n + v);
			if ( v != u && nodes[v].included == false && lenUV != INT_MAX
					&& nodes[v].distance > nodes[u].distance + lenUV) {
				nodes[v].distance = nodes[u].distance + lenUV;
				nodes[v].prevId = u;
			}
		}
		makeHeap(nodes, nheap, curlen);
	}

	if (nodes[to].included == true) {
		int i = to;
		do {
			printf("%d ", i);
			i = nodes[i].prevId;
		} while (i != from);
		printf("\n");

		return 0;
	} else {
		printf("none\n");
		return 1;
	}
}



















