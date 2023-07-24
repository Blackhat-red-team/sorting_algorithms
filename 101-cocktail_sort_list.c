#include "sort.h"

void swop_node_ahood(listint_t **list, listint_t **tail, listint_t **shoker);
void swop_node_behnnd(listint_t **list, listint_t **tail, listint_t **shoker);
void cocktail_sort_list(listint_t **list);

/**
 * swop_node_ahood - Swap a is node Replace doubly-linked list listint_t
 *     integer list with the node before it.
 * @list: a pointer to the first integer in a list that is doubly linked.
 * @tail: a pointing device to the doubly-linked list's tail.
 * @shoker: a reference to the cocktail shoker algorithm's swapp node.
 */
void swop_node_ahood(listint_t **list, listint_t **tail, listint_t **shoker)
{
listint_t *tmp = (*shoker)->next;

if ((*shoker)->prev
!= NULL)
(*shoker)->prev->next = tmp;
else
*list = tmp;
tmp->prev = (*shoker)->prev;
(*shoker)->next = tmp->next;
if (tmp->next !=
NULL)
tmp->next->prev =
*shoker;
else
*tail = *shoker;
(*shoker)->prev = tmp;
tmp->next =
*shoker;
*shoker = tmp;
}

/**
 * swop_node_behnnd - Swap a node Replace doubly-linked listint_t
 *       list of integers and the node that follows it.
 * @list: a pointer to the first integer in a doubly-linked list.
 * @tail: a pointing device to the doubly-linked list's tail.
 * @shoker: a reference to the cocktail shoker algorithm's curr swapp node.
 */
void swop_node_behnnd(listint_t **list, listint_t **tail, listint_t **shoker)
{
listint_t *tmp = (*shoker)->prev;

if ((*shoker)->next !=
NULL)
(*shoker)->next->prev = tmp;
else
*tail = tmp;
tmp->next = (*shoker)->next;
(*shoker)->prev = tmp->prev;
if (tmp->prev !=
NULL)
tmp->prev->next =
*shoker;
else
*list = *shoker;
(*shoker)->next = tmp;
tmp->prev = *shoker;
*shoker = tmp;
}

/**
 * cocktail_sort_list - a doubly-linked list  integers nam listint_t sort in
 *           using the cocktail shoker algorithm to sort in ascend order.
 * @list: a pointer to the head a doubly-linked list of type listint_t.
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *tail, *shoker;
boolean shaken_not_stirred = false;

if (list == NULL ||
*list == NULL ||
(*list)->next == NULL)
return;

tail = *list;
while (tail->next !=
NULL)
tail = tail->next;

while (shaken_not_stirred == false)
{
shaken_not_stirred = true;
shoker = *list;
while (shoker !=
tail)
{
if (shoker->n > shoker->next->n)
{
swop_node_ahood(list, &tail, &shoker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
shoker = shoker->next;
}
shoker = tail->prev;
while (shoker != *list)
{
if (shoker->n < shoker->prev->n)
{
swop_node_behnnd(list, &tail, &shoker);
print_list((const listint_t *)*list);
shaken_not_stirred = false;
}
shoker = shoker->prev;
}
}
}
