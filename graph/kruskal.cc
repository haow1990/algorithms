#include <algorithm>
#include <cstdio>
using namespace std;

void unionset_union(int array[], int i, int j)
{
	array[j] = i;
}

bool unionset_issame(int array[], int i, int j)
{
	int rooti = i;
	while (array[rooti] != rooti) {
		rooti = array[rooti];
	}

	int rootj = j;
	while (array[rootj] != rootj) {
		rootj = array[rootj];
	}

	array[i] = rooti;
	array[j] = rootj;

	return rooti == rootj;
}

struct Edge {
	int a, b;
	int weight;
};

static inline bool operator<(const Edge &e1, const Edge &e2)
{
	return e1.weight < e2.weight;
}

bool krucial(const int *graph, const int n)
{
	int nedge = 0;
	Edge edges[n*n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			edges[nedge].a = i;
			edges[nedge].b = j;
			edges[nedge].weight = *(graph + i * n + j);
			++nedge;
		}
	}

	sort(edges, edges + nedge);

	int k = 0;	// current edges in mst
	int m = 0;	// current edge for traverse
	int uu[n];
	for (int i = 0; i < n; ++i) {
		uu[i] = i;
	}
	while (true) {
		if (k == n - 1) {
			for (int i = 0; i < n - 1; ++i) {
				printf("<%d, %d>\n", edges[i].a, edges[i].b);
			}
			return true;
		}
		if (m >= nedge) {
			printf("no\n");
			return false;
		}
		if (unionset_issame(uu, edges[m].a, edges[m].b) == false) {
			// add to mst
			unionset_union(uu, edges[m].a, edges[m].b);
			edges[k] = edges[m];
			++k;
		}

		++m;
	}
}

int main()
{
	int graph[4][4] = {
		{0, 1, 2, 4},
		{1, 0, 2, 1},
		{2, 2, 0, 3},
		{4, 1, 3, 0}
	};

	krucial(&graph[0][0], 4);

	return 0;
}

