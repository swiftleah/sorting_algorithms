#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using Bubble sort algorithm
 * @array: array of integers to be sorted
 * @size: size of array of integers
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t j, i;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j + 1] < array[j])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
