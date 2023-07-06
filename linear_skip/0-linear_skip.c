#include "search.h"
/**
 * linear_skip - a function that searches for a value in a sorted skip list
 * @list:  is a pointer to the head of the skip list
 * @value: is the value to search for
 * Return: Pointer or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t size;
	skiplist_t *x, *temp;

	if (!list)
		return (NULL);

	x = list, temp = list;
	while (x && x->next && (x->n) < value)
	{
		temp = x;

		if (x->express)
		{
			x = x->express;

			printf("Value checked at index [%lu] = [%d]\n",
					x->index, x->n);
		}
		else
			while (x->next)
				x = x->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			temp->index, x->index);

	for (size = temp->index;
			size <= (x->index) && (temp->n <= value);
			size++, temp = temp->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", size, temp->n);
		if (temp && (temp->n) == value)
			return (temp);
	}

	if (temp)
		printf("Value checked at index [%lu] = [%d]\n", size, temp->n);

	return (NULL);
}
