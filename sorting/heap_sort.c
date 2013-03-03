#include <stddef.h>

static inline void swap(int array[], size_t i, size_t j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

static void sift_up(int array[], size_t i)
{
	size_t parent;
	while (i != 0) {
		parent = (i - 1) / 2;
		if (array[i] > array[parent]) {
			swap(array, i, parent);
			i = parent;
		} else {
			break;
		}
	}
}

static void sift_down(int array[], size_t len)
{
	size_t i = 0;
	size_t maxchildidx, leftchildidx;
	int maxchileval;
	while (i * 2 + 1 < len) {
		leftchildidx = i * 2 + 1;
		if (leftchildidx + 1 < len && array[leftchildidx] <= array[leftchildidx + 1]) {
			maxchildidx = leftchildidx + 1;
		} else {
			maxchildidx = leftchildidx;
		}
		if (array[i] < array[maxchildidx]) {
			swap(array, i, maxchildidx);
			i = maxchildidx;
		} else {
			break;
		}
	}
}

void heap_sort(int array[], size_t len)
{
	// make max-heap
	int i;
	for (i = 0; i < len; ++i) {
		sift_up(array, i);
	}
	for (i = len - 1; i > 0; --i) {
		swap(array, 0, i);
		sift_down(array, i);
	}
}
