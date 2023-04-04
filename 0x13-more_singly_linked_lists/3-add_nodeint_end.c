#include "lists.h"
/**
 * add_nodeint_end - add a new node at the end of the list
 * @head: address of a node
 * @n: element to be inserted
 * Return: newnode
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode, *temp = *head;

	newnode = (listint_t *) malloc(sizeof(listint_t));
	if (!newnode)
		return (NULL);
	/* Creation of a new node */
	newnode->n = n;
	newnode->next = NULL;
	/* In case the new node is the first node */
	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	/* Traversal of the list till the end */
	while (temp->next)
		temp = temp->next;
	/* Assignment of the newnode's address to the last node*/
	temp->next = newnode;
	return (newnode);
}
