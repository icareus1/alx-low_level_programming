#include "lists.h"
 /**
  * listint_len - prints number of elements in the list
  * @h: contains the address of a node
  * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
