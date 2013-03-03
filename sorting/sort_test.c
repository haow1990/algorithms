#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void bubble_sort(int array[], size_t len);
void merge_sort(int array[], size_t begin, size_t end, int *buf);

int main(int argc, char **argv)
{
	if (argc != 3) {
		fprintf(stderr, "usage: %s <sort algorithm> <array size>\n", argv[0]);
		exit(-1);
	}

	int count = atoi(argv[2]);
	int *array = (int*)malloc(sizeof(int) * count);
	if (array == NULL) {
		perror("malloc error");
		exit(-1);
	}
	int i;
	srand(time(NULL));
	printf("sorting");
	for (i = 0; i < count; ++i) {
		array[i] = rand() & 0xff;
		printf(" %d", array[i]);
	}
	printf("\n");

	if (strcmp(argv[1], "bubble") == 0) {
		bubble_sort(array, count);
	} else if (strcmp(argv[1], "merge") == 0) {
		merge_sort(array, 0, count, NULL);
	} else if (strcmp(argv[1], "insert") == 0) {
		insert_sort(array, count);
	} else if (strcmp(argv[1], "heap") == 0) {
		heap_sort(array, count);
	} else {
		fprintf(stderr, "unknown sort algorithm\n");
		exit(-1);
	}
	printf("result is");
	for (i = 0; i < count - 1; ++i) {
		printf(" %d", array[i]);
		if (array[i] > array[i+1]) {
			printf("sort error\n");
			for (i = 0; i < count; ++i) {
				printf("%d ", array[i]);
			}

			exit(-1);
		}
	}
	if (count > 0) {
		printf(" %d", array[i]);
	}
	printf("\nsort OK\n");

	return 0;
}
