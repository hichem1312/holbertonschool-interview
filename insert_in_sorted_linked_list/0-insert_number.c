#include "lists.h"
/**
 * insert_node - I
 * @head: head
 * @number: r
 * Return: p
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *ptr, *new_idx;

ptr = NULL;
if (!head)
    return (NULL);
new_idx = malloc(sizeof(listint_t));
ptr = *head;
if (new_idx == NULL)
	return (NULL);
new_idx->n = number;
new_idx->next = NULL;
if ((*head)->n > new_idx->n)
{
    new_idx->next = *head;
    *head = new_idx;
	return (*head);
}
while (ptr->next && (ptr->next->n < new_idx->n))
{
    ptr = ptr->next;
}
new_idx->next = ptr->next;
ptr->next = new_idx;
return (new_idx);
}