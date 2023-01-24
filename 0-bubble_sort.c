#include "sort.h"


/**
 * * bubble_sort- Implementing bubble sort
 * * @array: array to be sorted
 * * @size: size of an array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, state;

	for (i = 0; i < size; i++)
	{
		state = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				state = 1;
			}

		}
		if (state == 0)
			break;
	}
}
