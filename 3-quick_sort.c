#include "sort.h"
#include <stdio.h>
/**
 * quick_sort - sort array of integer
 * @array:pointer of integer
 * @size:size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !size || !array)
		return;
	q_sort_recursive(array, 0, size - 1, size);
}

/**
 * q_sort_recursive - sort array of integer recursive calls
 * @array:pointer of integer
 * @start: start index of array part
 * @end: end index of array part
 * @size:size of array
 */
void q_sort_recursive(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot_index = 0;

	if (start < end)
	{
		pivot_index = lomutoPartition(array, start, end, size);
		if (pivot_index != 0)
		{
			q_sort_recursive(array, start, pivot_index - 1, size);
		}
		q_sort_recursive(array, pivot_index + 1, end, size);
	}
}

/**
 * lomutoPartition - every int in the left is lower than the pivot
 * @array:pointer of integer
 * @start: start index of array part
 * @end: end index of array part
 * @size:size of array
 * Return: pivot index
 */
size_t lomutoPartition(int *array, size_t start, size_t end, size_t size)
{
	size_t i;
	int pivot = array[end];
	size_t p_index = start;

	for (i = start; i < end; i++)
	{

		if (array[i] <= pivot)
		{
			/*dont do any thing if ints the same*/
			if (array[p_index] != array[i])
			{
				swap(&array[p_index], &array[i]);
				print_array(array, size);
			}
			p_index++;
		}
	}

	if (array[p_index] != array[end])
	{
		swap(&array[p_index], &array[end]);
		print_array(array, size);
	}

	return (p_index);
}

/**
 * swap - Swaps the values of two integers using pointers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void swap(int *x, int *y)
{
	int tmp = *x;

	*x = *y;
	*y = tmp;
}
