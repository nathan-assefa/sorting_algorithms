#include "sort.h"
#include <stdbool.h>

/**
 * _swap- to swap to numbers
 * @array: an array whose element is swapped
 * @size: size of an array
 * @a: number to be swapped
 * @b: number to be swapped
 */
void _swap(int *array, int size, int *a, int *b)
{
	if (*a != *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
	print_array(array, size);
}

/**
 * hoare_partition- to sort the array recursively
 * @array: array to be sorted
 * @size: size of an array
 * @low: the first index of an array
 * @high: the last index of an array
 * Return: the last index
 */
int hoare_partition(int array[], int size, int low, int high)
{
	int i, j, pivot_value;

	pivot_value = array[high];
	i = low - 1, j = high + 1;

	while (true)
	{
		while (array[++i] < pivot_value)
			;
		while (array[--j] > pivot_value)
			;
		if (i >= j)
			return (i);

		_swap(array, size, &array[i], &array[j]);
	}
}

/**
 * hoare_recursion- Recursive call
 * @array: array to be sorted recursivley
 * @size: size of an array
 * @low: the first index of an array
 * @high: the last index of an array
 */
void hoare_recursion(int *array, int size, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = hoare_partition(array, size, low, high);
		hoare_recursion(array, size, low, pivot_idx - 1);
		hoare_recursion(array, size, pivot_idx, high);
	}
}

/**
 * quick_sort_hoare- implementing quick_sort_hoare
 * @array: array to be sorted
 * @size: size of an array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array && size >= 2)
		hoare_recursion(array, size, 0, size - 1);
}

