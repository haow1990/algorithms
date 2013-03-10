#include <stddef.h>

static void swap(int array[], int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

size_t partition(int array[], size_t start, size_t end)
{
	int x = array[end - 1];
	int less_end = start;	// 
	int i;
	for (i = start; i < end - 1; ++i) {
		if (array[i] <= x) {
			swap(array, less_end, i);
			++less_end;
		}
	}
	swap(array, less_end, end - 1);
	return less_end;
}

// [start, end)
void quick_sort(int array[], size_t start, size_t end)
{
	if (end <= start) {
		return;
	}
	
	size_t mid = partition(array, start, end);
	quick_sort(array, start, mid);
	quick_sort(array, mid + 1, end);
}
