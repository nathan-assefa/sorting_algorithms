#include "sort.h"
#include <stdbool.h>

/**
 * * bubble_sort- Writting bubble sort
 * * @array: an array to be sorted using bubble sort
 * * @size: size of an array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = size, j, state = 0;

	if (!array && size < 2)
		return;

	while (!state)
	{
		state = 1;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				state = 0;
			}
		}
		i--;
	}
}

/**
 * * swap- To swap two integers
 * * @a: first integer to be swapped
 * * @b: second number to be swapped
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
