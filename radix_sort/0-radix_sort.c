#include "sort.h"

/**
* radix_sort - a function that sorts an array of integers in ascending order
* @array: array
* @size: size of the array
*/

void radix_sort(int *array, size_t size)
{
	int count[1000], A[1000][1000], i = 0, j = 0, x = 0, y = 0, k = 0, q = 0;
	int max_digit = array[0], max = 0, digits = 0, div = 1;

	if (size < 2)
		return;
	for (k = 1; k < (int)size; k++)
	{
	if (array[k] > max_digit)
		max_digit = array[k];
	}
	max = max_digit;
	while (max > 0)
	{
		digits++;
		max /= 10;
	}
	for (q = 0; q < digits; q++)
	{
		for (i = 0; i < 10; i++)
			count[i] = 0;
		for (i = 0; i < (int)size; i++)
		{
			y = (array[i] / div) % 10;
			A[y][count[y]] = array[i];
			count[y] += 1;
		}
		i = 0;
		for (x = 0; x < 10; x++)
		{
			for (j = 0; j < count[x]; j++)
			{
				array[i] = A[x][j];
				i++;
			}
		}
		div *= 10;
		print_array(array, size);
	}
}