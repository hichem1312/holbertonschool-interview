#include "sort.h"

/**
 * merge_sort - sort an array of integers in ascending order using Merge Sort
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(size * sizeof(int));

	if (tmp == NULL)
		return;

	merge(array, size, tmp);
	free(tmp);
}

/**
 * merge - merge function
 * @array: array to merge
 * @size: size of the array
 * @tmp:temp
 */
void merge(int *array, size_t size, int *tmp)
{
	size_t left_side = size / 2, right_side = size - left_side;
	size_t v = 0, i = 0, j = 0;
	int *tmp_array = array + left_side;

	if (size <= 1)
		return;

	merge(array, left_side, tmp);
	merge(tmp_array, right_side, tmp);

	for (i = 0; i < left_side; i++)
		tmp[i] = array[i];

	printf("Merging...\n[left]: ");
	print_array(array, left_side);
	printf("[right]: ");
	print_array(tmp_array, right_side);

	i = 0;

	while (i < left_side || j < right_side)
	{
		while (j < right_side && (i >= left_side || tmp_array[j] < tmp[i]))
			array[v++] = tmp_array[j++];
		while (i < left_side && (j >= right_side || tmp_array[j] >= tmp[i]))
			array[v++] = tmp[i++];
	}

	printf("[Done]: ");
	print_array(array, size);
}
