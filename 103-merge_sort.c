#include "sort.h"

/**
 * * merge- To merge the sorted arrays
 * * @array: an array to be sorted
 * * @buf: copy of an array
 * * @low: The first idext in the array
 i* * @mid: the middle index
 * * @high: the lase index in the array
 */
void merge(int *array, size_t low, size_t mid, size_t high, int *buf)
{
	size_t i, j, k;

	i = low;
	j = mid;

	printf("Merging...\n[Left]: ");
	print_array(array + low, mid - low);
	printf("[Right]: ");
	print_array(array + mid, high - mid);
	for (k = low; k < high; k++)
	{
		if (i < mid && (j >= high || array[i] <= array[j]))
			buf[k] = array[i++];
		else
			buf[k] = array[j++];
	}
	printf("[Done]: ");
	print_array(buf + low, high - low);
}

/**
 * * merge_recursion- Recursive process to divide an array
 * * @array: array to be divided
 * * @low: first index of an array
 * * @high: lase index of an array
 * * @buff: copy of an array
 */
void merge_recursion(int *array, size_t low, size_t high, int *buff)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = low + (high - low) / 2;
		merge_recursion(buff, low, mid, array);
		merge_recursion(buff, mid, high, array);
		merge(buff, low, mid, high, array);
	}
}


/**
 * * merge_sort - sorts by merge sort algorithm
 * * @array: the integer array to sort
 * * @size: the size of the array
 * *
 * * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	for (i = 0; i < size; i++)
		buffer[i] = array[i];

	merge_recursion(array, 0, size, buffer);
	free(buffer);
}

