#include "sort.h"
#include <stdio.h>

/**
 * merge - merge two sorted array
 * @array: array of integer.
 * @temp: temporary array.
 * @left: start idx of subarray.
 * @mid: middle idx of array.
 * @right: end idx of subarray.
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	for (i = left, j = mid + 1; i <= mid && j <= right; k++)
	{
		if (array[i] <= array[j])
			temp[k] = array[i++];
		else
			temp[k] = array[j++];
	}
	while (j <= right)
		temp[k++] = array[j++];
	while (i <= mid)
		temp[k++] = array[i++];

	for (i = left; i <= right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort_recursive - separate array in one element
 * @array: array of integer.
 * @temp: temporary array.
 * @left: start of subarray.
 * @right: end of subarray.
 */
void merge_sort_recursive(int *array, int *temp, int left, int right)
{
	int mid;

	if (left >= right)
		return;
	mid = left + (right - left) / 2;
	if ((left + right) % 2 == 0)
		mid--;
	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - sor array of integer in merge alogorithm.
 * @array: array of integer.
 * @size: size of array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (!temp)
		return;
	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}
