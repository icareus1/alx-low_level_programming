#include "lists.h"
/**
 * free_listint - frees the list
 * @head: contains the address of the node
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		*temp = head;
		free(head);
		head = temp->next;
	}
}
