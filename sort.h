#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
/* -------------- helper function --------------*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap(int *x, int *y);
void q_sort_recursive(int *array, size_t start, size_t end, size_t size);
size_t lomutoPartition(int *array, size_t start, size_t end, size_t size);
/* -------------- sorting function --------------*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
#endif
