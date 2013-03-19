#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int len;
	int pre;
}lis_t;

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "usage: %s { num}\n", argv[0]);
		return 1;
	}

	int len = argc - 1;
	int *array = (int*)malloc(sizeof(int) * len);
	lis_t *d = (lis_t*)malloc(sizeof(lis_t) * len);

	array[0] = atoi(argv[1]);
	d[0].len = 1;
	d[0].pre = -1;

	int i, j, max, maxi, maxofall = 0, maxiofall = -1;
	for (i = 1; i < len; ++i) {
		array[i] = atoi(argv[i+1]);
		max = 0;
		maxi = -1;
		for (j = 0; j < i; ++j) {
			if (d[j].len > max && array[j] < array[i]) {
				max = d[j].len;
				maxi = j;
			}
		}
		d[i].len = max + 1;
		d[i].pre = maxi;

		if (maxofall < d[i].len) {
			maxofall = d[i].len;
			maxiofall = i;
		}
	}

	i = maxiofall;
	while (d[i].pre != -1) {
		printf("%d ", array[i]);
		i = d[i].pre;
	}
	printf("%d\n", array[i]);

	return 0;
}
