#include "sort.h"
#include <stdio.h>

int HoarePartition(int *array, int start, int end, size_t size);
void q_sort_recursive(int *array, int start, int end, size_t size);
/**
 * quick_sort_hoare - sort array of integer
 * @array:pointer of integer
 * @size:size of array
 */
void quick_sort_hoare(int *array, size_t size)
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
void q_sort_recursive(int *array, int start, int end, size_t size)
{
	int pivot_index = 0;

	if (start < end)
	{
		pivot_index = HoarePartition(array, start, end, size);

		q_sort_recursive(array, start, pivot_index, size);

		q_sort_recursive(array, pivot_index + 1, end, size);
	}
}

/**
 * HoarePartition - every int in the left is lower than the pivot
 * @array:pointer of integer
 * @start: start index of array part
 * @end: end index of array part
 * @size:size of array
 * Return: pivot index
 */
int HoarePartition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j = end + 1;

	while (1)
	{
		do

		{
			i++;
		} while (array[i] < pivot);

		do

		{
			j--;
		} while (array[j] > pivot);

		if (i > j)
			return (j);

		if (array[i] != array[j])
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
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
