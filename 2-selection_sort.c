#include "sort.h"

/**
 * * selection_sort- Implementing selection sort
 * * @array: array to be soreted
 * * @size: size of an array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;
	int tmp;

	if (!array && size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		pos = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
			{
				pos = j;
			}
		}
		if (array[pos] != array[i])
		{
			tmp = array[pos];
			array[pos] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
