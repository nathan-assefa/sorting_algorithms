#include "sort.h"

/**
 * * bubble_sort- Writting bubble sort
 * * @array: an array to be sorted using bubble sort
 * * @size: size of an array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, state;

	if (!array && size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		state = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				state = 1;
			}
		}
		if (state == 0)
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
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
