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
	for (i = 0; i < count; ++i) {
		array[i] = rand() & 0xff;
	}

	if (strcmp(argv[1], "bubble") == 0) {
		bubble_sort(array, count);
	} else if (strcmp(argv[1], "merge") == 0) {
		merge_sort(array, 0, count, NULL);
	} else {
		fprintf(stderr, "unknown sort algorithm\n");
		exit(-1);
	}
	for (i = 0; i < count - 1; ++i) {
		if (array[i] > array[i+1]) {
			printf("sort error\n");
			for (i = 0; i < count; ++i) {
				printf("%d ", array[i]);
			}

			exit(-1);
		}
	}
	printf("sort OK\n");

	return 0;
}
