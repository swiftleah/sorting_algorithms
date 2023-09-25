#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array of ints to be sorted
 * @size: size of the array
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int max = array[0];
	int min = array[0];
	int *count = NULL, *output = NULL;
	size_t i;

	if (size < 2 || array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	count = malloc(sizeof(int) * (max - min + 1));
	if (count == NULL)
		return;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i <= (size_t)(max - min); i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i] - min]++;
	for (i = 0; i <= (size_t)(max - min); i++)
		printf("%d%s", count[i], (i == (size_t)(max - min)) ? "\n" : ", ");
	for (i = 1; i <= (size_t)(max - min); i++)
		count[i] += count[i - 1];
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i] - min] - 1] = array[i];
		count[array[i] - min]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
