#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * find_listint_loop -  a function that finds the loop in a linked list
 * @head: head of a linked list
 * Return: NULL
 */
listint_t *find_listint_loop(listint_t *head)
{

	listint_t *a;
	listint_t *b;

	if (head == NULL || head->next == NULL)
	{
		return (NULL);
	}
	a = head->next;
	b = head->next->next;
	while (b && b->next)
	{
		if (a == b)
		{
			a = head;
			while (a != b)
			{
				a = a->next;
				b = b->next;
			}
			return (a);
		}
		a = a->next;
		b = b->next->next;
	}

	return (NULL);
}
