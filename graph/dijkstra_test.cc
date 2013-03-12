#include <climits>

int dijkstra(int *graph, const int n, int from, int to);

int main()
{
	int graph[7][7] = {
		{0, 2, INT_MAX, INT_MAX, INT_MAX, 6, INT_MAX},
		{2, 0, 3, INT_MAX, INT_MAX, INT_MAX, 4},
		{INT_MAX, 3, 0, 9, INT_MAX, INT_MAX, 2},
		{INT_MAX, INT_MAX, 9, 0, 3, INT_MAX, INT_MAX},
		{INT_MAX, INT_MAX, INT_MAX, 3, 0, 10, 1},
		{6, INT_MAX, INT_MAX, INT_MAX, 10, 0, 1},
		{INT_MAX, 4, 2, INT_MAX, 1, 1, 0}
	};

	return dijkstra(&graph[0][0], 7, 0, 3);
}
