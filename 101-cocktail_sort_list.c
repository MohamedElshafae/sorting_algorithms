#include "sort.h"

int swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - Swaps the nodes of d-linkedlist
 * @list: head pointer
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = NULL;
	listint_t *end = NULL, *current = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do

	{
		swapped = 0;
		current = *list;
		while (current->next != end && current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current == *list)
					*list = current->next;

				swapped = 1;
				current = current->next;
				swap_nodes(list, current->prev, current);
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;

		current = current->prev;
		while (current->prev != start && current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				current = current->prev;
				swapped = swap_nodes(list, current, current->next);
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - Swaps the nodes of d-linkedlist
 * @list: head pointer
 * @n1: node1 pointer
 * @n2: node2 pointer
 * Return: 1
 */
int swap_nodes(listint_t **list, listint_t *n1, listint_t *n2)
{
	n1->next = n2->next;

	if (n2->next != NULL)
		n2->next->prev = n1;

	n2->next = n1;
	n2->prev = n1->prev;

	if (n1->prev != NULL)
		n1->prev->next = n2;
	else
		*list = n2;

	n1->prev = n2;

	return (1);
}
