#include "lists.h"
/**
 * add_nodeint - add a new node at the beginning of the list
 * @head: contains the address of the first node
 * @n: element to be inserted
 * Return: the new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = (listint_t *) malloc(sizeof(listint_t));
	if (!newnode)
		return (NULL);
	newnode->n = n;
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}
