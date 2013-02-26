#include <stddef.h>

void swap(int array[], int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void bubble_sort(int array[], size_t len)
{
	int i, j;
	for (i = len - 1; i > 0; --i) {
		for (j = 0; j < i; ++j) {
			if (array[j] > array[j+1]) {
				swap(array, j+1, j);
			}
		}
	}
}

