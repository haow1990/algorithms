#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

// [begin, end)
void merge_sort(int array[], size_t begin, size_t end, int *buf)
{
	if (end <= begin + 1) {		// one or no elements
		return;
	}

	int *tmp = buf;
	if (buf == NULL) {
		tmp = (int*)malloc(sizeof(int) * (end + 2));
	}

	int mid = begin + (end - begin) / 2;
	merge_sort(array, begin, mid, tmp);
	merge_sort(array, mid, end, tmp);

	int i, j;
	for (i = begin; i < mid; ++i) {
		tmp[i] = array[i];
	}
	tmp[mid] = INT_MAX;
	for (i = mid; i < end; ++i) {
		tmp[i + 1] = array[i];
	}
	tmp[end + 1] = INT_MAX;
	int m = begin;
	for (i = begin, j = mid + 1; m < end;) {
		if (tmp[i] < tmp[j]) {
			array[m++] = tmp[i++];
		} else {
			array[m++] = tmp[j++];
		}
	}
	if (buf == NULL) {
		free(tmp);
	}
}
