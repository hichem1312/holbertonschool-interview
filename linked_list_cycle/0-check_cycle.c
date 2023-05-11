#include "lists.h"
/**
 * check_cycle -  a function in C that checks if a singly linked list has a cycle in it.
 * @list: Pointer
 * Return: 0
 */
int check_cycle(listint_t *list)
{
	listint_t *first;
	listint_t *second;

	if (!list || !list->next)
		return (0);
    first = list->next;
	second = list->next->next;
	while (first && second && second->next)
	{
		if (first == second)
			return (1);
        first = first->next;
		second = second->next->next;
	}
	return (0);
}