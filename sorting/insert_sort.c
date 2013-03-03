#include <stddef.h>

void insert_sort(int array[], size_t len)
{
	size_t i, j, tmp;
	for (i = 1; i < len; ++i) {
		tmp = array[i];
		for (j = i; j > 0; --j) {
			if (tmp < array[j-1]) {
				array[j] = array[j-1];
			} else {
				break;
			}
		}
		array[j] = tmp;
	}
}
