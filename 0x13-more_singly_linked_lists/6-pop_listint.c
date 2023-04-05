#include "lists.h"
/**
 * pop_listint - deletes the first node & returns its value
 * @head: contains the address of the first node
 * Return: the popped element
 */
int pop_listint(listint_t **head)
{
	listint_t *temp = head;
	int val;

	if (!head || !*head)
		return (0);

	val = *head->n;
	*head = *head->next;
	free(temp);

	return (val);
}
