#include "lists.h"
/**
 * get_nodeint_at_index - display a node at a certain index
 * @head: contains the address of the first node
 * @index: position of the node to be printed
 * Return: NULL if node doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *currentnode = head;
	unsigned int pos = 0;

	while (currentnode)
	{
		if (pos == index)
			return (currentnode);
		pos++;
		currentnode = currentnode->next;
	}
	return (NULL);
}
