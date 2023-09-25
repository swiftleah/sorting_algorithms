#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* Struct: */

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

/* Prototypes: */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2);

/* Task 0: */
void bubble_sort(int *array, size_t size);

/* Task 1: */
void insertion_sort_list(listint_t **list);

/* Task 2: */
void selection_sort(int *array, size_t size);

/* Task 3: */
void quick_sort(int *array, size_t size);

/* Task 4: */
void shell_sort(int *array, size_t size);

/* Task 5: */
void cocktail_sort_list(listint_t **list);

/* Task 6: */
void counting_sort(int *array, size_t size);

#endif
