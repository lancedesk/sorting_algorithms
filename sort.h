#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdint.h>
#include <errno.h>

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


void insertion_sort_list(listint_t **list);
void quick_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif
