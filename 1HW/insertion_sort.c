#include "Insertion_sort.h"

/** 
 * insertion_sort() - sorts array into increasing order.
 * @array:	The array to sort.
 * @len:	Number of elements in array.
 *
 * Uses optimized insertion sort (Jon Bentley, 2000).
 * See https://en.wikipedia.org/wiki/Insertion_sort for algorithm.
 */
void insertion_sort(int *array, int len)
{
	int	i, j;
	int	tmp;

	for (i = 1; i < len; i++) {
		j = i;
		tmp = array[j];
		while (j > 0 && array[j-1] > tmp) {
			array[j] = array[j-1];
			j--;
		}
		array[j] = tmp;
	}
}

