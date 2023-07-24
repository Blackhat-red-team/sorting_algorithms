#include "sort.h"

/**
 * swop_nodas - Swap nodas In a listint_t doubly-linked list.
 * @h: a pointing device at the doubly-linked list's head.
 * @n3: a marker for the starting node of the swap.
 * @n4: the following node to switch.
 */
void swop_nodas(listint_t **h, listint_t **n3, listint_t *n4)
{
(*n3)->next = n4->next;
if (n4->next != NULL)
n4->next->prev = *n3;
n4->prev = (*n3)->prev;
n4->next = *n3;
if ((*n3)->prev != NULL)
(*n3)->prev->next = n4;
else
*h = n4;
(*n3)->prev = n4;
*n3 = n4->prev;
}

/**
 * insertion_sort_list - a doubly linked list of integers is sorted
 *     application of the insertion sort algorithm.
 * @list: a pointer to the first integer in a doubly-linked list.
 * Description: the list is printed after each swap.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *itar, *innert, *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

for (itar = (*list)->next; itar != NULL; itar = tmp)
{
tmp = itar->next;
innert = itar->prev;
while (innert != NULL && itar->n < innert->n)
{
swop_nodas(list, &innert, itar);
print_list((const listint_t *)*list);
}
}
}
