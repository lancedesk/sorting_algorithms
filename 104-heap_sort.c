#include "sort.h"

void heapify(int *array, size_t size, size_t i);

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void heap_sort(int *array, size_t size)
{
	size_t i;

	/* Build max heap */
	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1);

	/* Heap sort */
	for (i = size - 1; i > 0; i--)
	{
		/* Swap root (maximum element) with the last element */
		int temp = array[0];

		array[0] = array[i];
		array[i] = temp;

		print_array(array, size);

		/* Heapify the reduced heap */
		heapify(array, i, 0);
	}
}

/**
 * heapify - Builds a max heap from an array
 * @array: The array to be heapified
 * @size: The size of the array
 * @i: The root index of the heap
 */

void heapify(int *array, size_t size, size_t i)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;
	int temp;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		/* Swap array[i] and array[largest] */
		temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;

		print_array(array, size);

		/* Recursively heapify the affected sub-tree */
		heapify(array, size, largest);
	}
}

