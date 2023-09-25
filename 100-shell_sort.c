#include "sort.h"

/**
 * swap_ints - swaps two ints
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmpo;

	tmpo = *a;
	*a = *b;
	*b = tmpo;
}

/**
 * shell_sort - sort an array of ints in ascending order
 * @array: array of ints
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				swap_ints(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
