#include "sort.h"

void quicksort_hoare_recursive(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void swap_elements(int *array, int i, int j, size_t size);
/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with the Hoare partition scheme
 * @array: The array to be sorted
 * @size: The size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_hoare_recursive - Recursive helper function for quick_sort_hoare
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: The size of the array
 */

void quicksort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = hoare_partition(array, low, high, size);
		quicksort_hoare_recursive(array, low, pivot_index, size);
		quicksort_hoare_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * hoare_partition - Partitions an array using the Hoare scheme
 * @array: The array to be sorted
 * @low: The low index of the partition to be sorted
 * @high: The high index of the partition to be sorted
 * @size: The size of the array
 * Return: The index of the pivot element after partitioning
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_elements(array, i, j, size);
	}
}

/**
 * swap_elements - Swaps two elements in an array and prints the array
 * @array: The array containing the elements
 * @i: The index of the first element to be swapped
 * @j: The index of the second element to be swapped
 * @size: The size of the array
 */

void swap_elements(int *array, int i, int j, size_t size)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

