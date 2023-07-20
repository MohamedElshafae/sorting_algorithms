#include "sort.h"

/**
 * bubble_sort - sorts array of intgers
 *
 * @array: Pointer to int array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swaped = -1;

	if (size < 2 || !size || !array)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swaped = 0;
			}
		}
		if (swaped == -1)
			break;
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
