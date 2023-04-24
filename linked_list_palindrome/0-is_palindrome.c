#include "lists.h"
/**
 * is_palindrome - a function in C that checks if a singly linked list is a palindrome.
 * @head: head
 * Return: 0
 */
int is_palindrome(listint_t **head)
{

	int i, x, *node;
	if (head == NULL)
	{
		return (1);
	}
	x = 0;
	node = malloc(sizeof(listint_t));
	while (*head)
	{
		node[x] = (*head)->n;
		x++;
		(*head) = (*head)->next;
	}
	for (i = 0; i <= x / 2 && x != 0; i++)
	{
		if (node[i] != node[x - i - 1])
		{
			return (0);
		}
	}
	return (1);
}