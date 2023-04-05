#include "lists.h"
/**
 * delete_nodeint_at_index - deletion of element at a position/index
 * @head: contains the address of the node
 * @index: position/index of the element to be deleted
 * Return: 1 on Success, otherwise -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head, *currentnode;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (i < index - 1)
	{
		if (!temp || !(temp->next))
			return (-1);
		temp = temp->next;
		i++;
	}
	currentnode = temp->next;
	temp->next = currentnode->next;
	free(currentnode);
	return (1);
}
