#include "sort.h"

/**
 * * shell_sort- implementing shell_sort
 * * @array: an array to be sorted
 * * @size: size of an array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap, n;
	int tmp;

	n = 1;
	while (n < size)
	{
		n = n * 3 + 1;
	}



	for (gap = n / 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] >= tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
