#include "sort.h"

/**
 * get_max - get the the biggest number in array
 * @array: array of integer
 * @size: size of array
 * Return: the biggest number in array
 */
int get_max(int *array, size_t size)
{
	int i, max = 0;

	for (i = 0; i < (int)size; i++)
		if (max < array[i])
			max = array[i];
	return (max);
}
/**
 * counting_sort - sort array of integer by counting sort algorithm.
 * @array: array of integer.
 * @size: size of array.
 */
void counting_sort(int *array, size_t size)
{
	int i, j, idx, count_size, *count, *sorted;

	if (!array || size < 2)
		return;

	count_size = get_max(array, size) + 1;
	sorted = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * count_size);

	if (!count || !sorted)
		return;

	for (i = 0; i < (int)size; i++)
	{
		j = array[i];
		count[j] += 1;
	}
	for (i = 0; i < count_size - 1; i++)
		count[i + 1] += count[i];
	print_array(count, count_size);

	for (i = size - 1; i >= 0; i--)
	{
		j = array[i];
		count[j]--;
		idx = count[j];
		sorted[idx] = j;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];
	free(count);
	free(sorted);
}
