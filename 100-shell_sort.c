#include "sort.h"

/**
 * shell_sort - sort array of integer in shell way.
 * @array: array of integer.
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, h = 1;

	if (!array || size < 2)
		return;
	while (h < ((int)size / 3))
		h = 3 * h + 1;

	while (h >= 1)
	{
		for (i = h; i < (int)size; i++)
		{
			j = i;

			while (j >= h && array[j] < array[j - h])
			{
				swap(&array[j], &array[j - h]);
				j -= h;
			}
		}
		h /= 3;
		print_array(array, size);
	}
}

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
