#include "lists.h"
/**
 * print_listint -  prints all the elements of the list
 * @h: contains the address of a node
 * Return: number of elements
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d", h->n);
		count++;
		h = h->next;
	}
	return (count);
}
