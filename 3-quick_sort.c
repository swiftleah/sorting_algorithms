#include "sort.h"

/**
 * swap_ints - swap two ints
 * @a: first int
 * @b: second int
 */
void swap_ints(int *a, int *b)
{
	int tmpo;

	tmpo = *a;
	*a = *b;
	*b = tmpo;
}

/**
 * lomuto_partition - orders a set of array of ints according to
 * the lomuto partition
 * @array: array of ints
 * @size: size of array
 * @left: starting index of the set to order
 * @right: ending of the index
 *
 * Return: final partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - starts the quicksort algorithm through recursion
 * @array: array of ints to sort
 * @size: size of array
 * @left: starting index of the array to order
 * @right: ending of index
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts an array of ints in ascending order using
 * quicksort algorithm
 * @array: array of ints
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
