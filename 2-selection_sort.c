#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 * Selection sort algorthim
 * @array: array of integers to be sorted
 * @size: size of array of integers
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t smallest_num;
	size_t i, j;
	int temp;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		smallest_num = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_num])
			{
				smallest_num = j;
			}
		}

		if (i != smallest_num)
		{
			temp = array[i];
			array[i] = array[smallest_num];
			array[smallest_num] = temp;

		}
		print_array(array, size);
	}
}
