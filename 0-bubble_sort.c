#include "sort.h"
#include <stdbool.h>

/**
 * * bubble_sort- Writting bubble sort
 * * @array: an array to be sorted using bubble sort
 * * @size: size of an array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool state;

	if (!array && size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		state = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				state = true;
			}
		}
		if (state)
			break;
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
