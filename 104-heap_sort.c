#include "sort.h"

void swap(int *x, int *y);
void build_max_heap(int *array, size_t size);
void max_heapify(int *array, size_t size, size_t i, size_t array_size);

/**
 * heap_sort - sort array of ints
 * @array: Pointer to the integer array representing the binary heap.
 * @size: The total size of the input 'array'.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	if (size < 2 || !size || !array)
		return;
	build_max_heap(array, size);

	for (i = size - 1; i >= 0; i--)
	{
		if (array[0] != array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
		}

		max_heapify(array, i, 0, size);
	}
}

/**
 * build_max_heap - Builds a max heap from an integer array.
 * @array: Pointer to the integer array representing the binary heap.
 * @size: The total size of the input 'array'.
 */
void build_max_heap(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		max_heapify(array, size, i, size);
}

/**
 * max_heapify - Maintains the max heap property of a binary heap.
 * @array: Pointer to the integer array representing the binary heap.
 * @size: The number of elements in the current sub-heap to heapify.
 * @i: Index of the node in the array to start the max heapify process.
 * @array_size: The total size of the input 'array'.
 */
void max_heapify(int *array, size_t size, size_t i, size_t array_size)
{
	size_t left_child = 2 * i + 1;
	size_t right_child = 2 * i + 2;
	size_t max = i;

	if ((left_child < size) && array[max] < array[left_child])
		max = left_child;

	if ((right_child < size) && array[max] < array[right_child])
		max = right_child;
	if (max != i)
	{
		if (array[0] != array[i])
		{
			swap(&array[i], &array[max]);
			print_array(array, array_size);
		}

		max_heapify(array, size, max, array_size);
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
