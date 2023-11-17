#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order
 * using the Insertion Sort algorithm
 *
 * @list: A pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current;

		while (
				insertion_point->prev != NULL &&
				insertion_point->n < insertion_point->prev->n
		      )
		{
			/* Swap nodes */
			prev_node = insertion_point->prev;
			next_node = insertion_point->next;

			prev_node->next = next_node;
			if (next_node != NULL)
				next_node->prev = prev_node;

			insertion_point->next = prev_node;
			insertion_point->prev = prev_node->prev;

			if (prev_node->prev != NULL)
				prev_node->prev->next = insertion_point;

			prev_node->prev = insertion_point;

			/* Update head of the list if needed */
			if (insertion_point->prev == NULL)
				*list = insertion_point;
			/* Print list after each swap */
			print_list(*list);
		}
		current = current->next;
	}
}

