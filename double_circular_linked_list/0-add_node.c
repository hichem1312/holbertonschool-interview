#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 *add_node_end - A function that add a new node to the end
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *head, *new_node;
	char *x;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	x = strdup(str);
	if (!x)
		return (NULL);
	new_node->str = x;
	if (!(*list))
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	head = *list;
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	return (new_node);
}

/**
 *add_node_begin - A function that add a new node to the beginning
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *head, *new_node;
	char *x;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	x = strdup(str);
	if (!x)
		return (NULL);
	new_node->str = x;
	if (!(*list))
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;

		return (new_node);
	}
	head = *list;
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	*list = new_node;
	return (new_node);
}
