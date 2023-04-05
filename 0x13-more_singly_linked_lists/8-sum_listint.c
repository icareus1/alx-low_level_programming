#include "lists.h"
/**
 * sum_listint - sum of the elements in the list
 * @head: contains the address of the first node
 * Return: the sum
 */
int sum_listint(listint_t *head)
{
	listint_t *temp = head;
	int sum = 0;

	while (temp)
	{
		sum += temp->n;
		temp = temp->next;
	}

return (sum);
}
