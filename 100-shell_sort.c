#include "sort.h"

/**
 * shell_sort - sort array of integer in shell way.
 * @array: array of integer.
 * @size: size of array.
 */
void shell_sort(int *array, size_t size)
{
	int i, j, h = 1, temp, flag = 0;

	if (!array || size < 2)
		return;
	while (1)
	{
		h = 3 * h + 1;
		if (h < (int)size)
			break;
	}

	while (h > 0)
	{
		for (i = h; i < (int)size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= h && temp < array[j - h])
			{
				array[j] = array[j - h];
				j -= h;
				flag = 1;
			}
			array[j] = temp;
		}
		h /= 3;
		if (flag == 1)
		{
			print_array(array, size);
			flag = 0;
		}
	}
}
