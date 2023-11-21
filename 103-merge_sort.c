#include "sort.h"

/**
 * copy_to_temp_arrays - Copies data to temporary arrays left[] and right[].
 * @array: The array to be sorted
 * @left: Temporary array for the left subarray
 * @right: Temporary array for the right subarray
 * @l: Left index of the subarray
 * @m: Middle index of the subarray
 * @n1: Size of the left subarray
 * @n2: Size of the right subarray
 */

void copy_to_temp_arrays(
		int *array, int *left,
		int *right, size_t l,
		size_t m,
		size_t n1,
		size_t n2
		)
{
	size_t i, j;

	for (i = 0; i < n1; i++)
		left[i] = array[l + i];

	for (j = 0; j < n2; j++)
		right[j] = array[m + 1 + j];
}

/**
 * merge_sorted_arrays - Merges two sorted subarrays back into array[l..r].
 * @array: The array to be sorted
 * @left: Temporary array for the left subarray
 * @right: Temporary array for the right subarray
 * @l: Left index of the subarray
 * @n1: Size of the left subarray
 * @n2: Size of the right subarray
 */

void merge_sorted_arrays(
		int *array,
		int *left,
		int *right,
		size_t l,
		size_t n1,
		size_t n2
		)
{
	size_t i = 0, j = 0, k = l;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}
}

/**
 * merge - Merges two subarrays of arr[].
 * The subarray arr[l..m] is merged with the subarray arr[m+1..r].
 * @array: The array to be sorted
 * @l: Left index of the subarray
 * @m: Middle index of the subarray
 * @r: Right index of the subarray
 */

void merge(int *array, size_t l, size_t m, size_t r)
{
	size_t n1 = m - l + 1;
	size_t n2 = r - m;

	/* Create temporary arrays */
	int *left = malloc(n1 * sizeof(int));
	int *right = malloc(n2 * sizeof(int));

	if (left == NULL || right == NULL)
	{
		free(left);
		free(right);
		return;
	}

	copy_to_temp_arrays(array, left, right, l, m, n1, n2);

	merge_sorted_arrays(array, left, right, l, n1, n2);

	/* Print the merging step */
	printf("[Done]: ");
	print_array(array + l, r - l + 1);

	/* Free temporary arrays */
	free(left);
	free(right);
}

/**
 * merge_sort_recursive - Recursively sorts an array
 * using the merge sort algorithm
 * @array: The array to be sorted
 * @l: Left index of the subarray
 * @r: Right index of the subarray
 */

void merge_sort_recursive(int *array, size_t l, size_t r)
{
	if (l < r)
	{
		/* Same as (l+r)/2, but avoids overflow for large l and r */
		size_t m = l + (r - l) / 2;

		/* Recursively sort the first and second halves */
		merge_sort_recursive(array, l, m);
		merge_sort_recursive(array, m + 1, r);

		/* Merge the sorted halves */
		merge(array, l, m, r);
	}
}

/**
 * merge_sort - Sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	printf("Merging...\n");

	/* Start the recursive sorting process */
	merge_sort_recursive(array, 0, size - 1);
}

