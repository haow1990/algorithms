#include <stdio.h>
#include <stdlib.h>

int knapsack01(int weight[], int value[], const int N, const int Capacity)
{
	int **d;
	int c, n;
	d = (int**)malloc(sizeof(int**) * (Capacity + 1));
	for (c = 0; c <= Capacity; ++c) {
		d[c] = (int*)malloc(sizeof(int*) * (N + 1));
	}

	for (c = 0; c <= Capacity; ++c) {
		d[c][0] = 0;
	}

	for (n = 0; n <= N; ++n) {
		d[0][n] = 0;
	}

	int yes, no;
	for (c = 1; c <= Capacity; ++c) {
		for (n = 1; n <= N; ++n) {
			// not large enough to hold object n-1
			if (c < weight[n-1]) {
				d[c][n] = d[c][n-1];
			} else {
				// don't hold object n - 1
				no = d[c][n-1];
				// hold
				yes = value[n-1] + d[c - weight[n-1]][n-1];
				if (yes > no) {
					d[c][n] = yes;
				} else {
					d[c][n] = no;
				}
			}
		}
	}

	printf("%d\n", d[Capacity][N]);

	return 0;
}

int main(int argc, char **argv)
{
	int weight[5] = {2, 4, 1, 8, 3};
	int value[5] =  {4, 4, 1, 100, 3};

	int capacity = 10;
	knapsack01(weight, value, 5, 10);

	return 0;
}

