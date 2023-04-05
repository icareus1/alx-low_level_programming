#include "lists.h"
/**
 * insert_nodeint_at_index - insertion at given position/index
 * @head: contains the address of the node
 * @idx: position/index to insert new node
 * @n: element to be inserted
 * Return: new node if successful, NULL if empty.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *newnode, *temp = *head;
	unsigned int i; /* i = position */

	new = (listint_t *) malloc(sizeof(listint_t));
	if (!newnode || !head)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (idx == 0)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			newnode->next = temp->next;
			temp->next = newnode;
			return (newnode);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}
