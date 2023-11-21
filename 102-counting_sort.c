#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void counting_sort(int *array, size_t size)
{
	int max = array[0];
	size_t i, j;
	int *counting_array;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create and initialize the counting array */
	counting_array = malloc((max + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		counting_array[i] = 0;

	/* Count the occurrences of each element in the array */
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(counting_array, max + 1); /* Print the counting array */

	/* Update the original array using the counting array */
	j = 0;
	for (i = 0; i <= (size_t)max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[j++] = i;
			counting_array[i]--;
		}
	}

	free(counting_array); /* Free the counting array */
}
