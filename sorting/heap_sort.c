#include <stddef.h>
#include <limits.h>

static inline void swap(int array[], size_t i, size_t j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

static inline void max_heapify(int array[], size_t i, size_t len)
{
    while (i * 2 + 1 < len) {
        int ileft = i * 2 + 1;
        int iright = ileft + 1;
        int left = array[ileft];
        int right = iright < len ? array[iright] : INT_MIN;
        int imax = left >= right ? ileft : iright;
        if (array[i] < array[imax]) {
            swap(array, i, imax);
            i = imax;
        } else {
            break;
        }
    }
}

void heap_sort(int array[], size_t len)
{
	// make max-heap
	int i;
	for (i = len / 2; i >= 0; --i) {
        max_heapify(array, i, len);
	}
	for (i = len - 1; i > 0; --i) {
		swap(array, 0, i);
        max_heapify(array, 0, i);
	}
}
