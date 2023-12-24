#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * siftdown - siftdown function
 * @array: the array
 * @i: the value to start with
 * @end: the end
 * @size: the size
 */

void siftdown(int *array, size_t size, size_t i, size_t end)
{
	size_t max = i, aux;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		aux = array[i];
		array[i] = array[max];
		array[max] = aux;
		print_array(array, end);
		siftdown(array, size, max, end);
	}
}

/**
 * heap_sort - Heap sort algorithm
 * @array: array to sort
 * @size: Number of elements
 */
void heap_sort(int *array, size_t size)
{
	size_t i, aux;
	size_t end = size;

	if (array != NULL)
	{
		for (i = size / 2 - 1; (int)i >= 0; i--)
			siftdown(array, size, i, end);
		for (i = size - 1; i > 0; i--)
		{
			aux = array[i];
			array[i] = array[0];
			array[0] = aux;
			print_array(array, size);
			siftdown(array, i, 0, end);
		}
	}
}
