#include "sort.h"

void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2);

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		/* Forward pass */
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, &start, &(start->next));
				swapped = 1;
				print_list(*list);
			}
		}

		if (swapped == 0)
			break;

		swapped = 0;

		/* Backward pass */
		for (end = start; end->prev != NULL; end = end->prev)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, &(end->prev), &end);
				swapped = 1;
				print_list(*list);
			}
		}
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @list: A pointer to the head of the doubly linked list
 * @node1: A pointer to the first node to swap
 * @node2: A pointer to the second node to swap
 */

void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *temp;

	if (*node1 == NULL || *node2 == NULL)
		return;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = *node2;
	else
		*list = *node2;

	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;

	(*node1)->next = (*node2)->next;
	(*node2)->prev = (*node1)->prev;
	(*node1)->prev = *node2;
	(*node2)->next = *node1;

	if ((*node1)->next != NULL)
		(*node1)->next->prev = *node1;

	temp = *node1;
	*node1 = *node2;
	*node2 = temp;
}

