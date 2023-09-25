#include "sort.h"

/**
 * swap_cocktail_nodes - swaps nodes of double linked list
 * for cocktail shaker sorting algorithm
 * @list: double pointer to double linked list
 * @node1: node 1
 * @node2: node 2
 * Return: nothing
 */

void swap_cocktail_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (*list == node1)
		*list = node2;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts double linked list of ints in ascending order
 * using cocktail shaker sort algorithm
 * @list: double linked list to sort
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *back = NULL, *forward = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;
		while (current->next != forward)
		{
			if (current->n > current->next->n)
			{
				swap_cocktail_nodes(list, current, current->next);
				swapped = 1;
			}
			else
			{
				current = current->next;
			}
		}
		if (!swapped)
			break;
		forward = current;
		swapped = 0;
		while (current->prev != back)
		{
			if (current->n < current->prev->n)
			{
				swap_cocktail_nodes(list, current->prev, current);
				swapped = 1;
			}
			else
			{
				current = current->prev;
			}
		}
		back = current;
	} while (swapped);
}
