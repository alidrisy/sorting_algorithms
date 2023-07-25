#include "sort.h"

void swap(listint_t **node, listint_t **list);

/**
* insertion_sort_list - sorts a doubly linked list in ascending order
* @list: pointer to doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
listint_t  *ne, *new, *curr;

if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
return;

ne = *list;
while (ne && ne->next)
{
if (ne->n > ne->next->n)
{
curr = ne;

swap(&curr, list);
print_list(*list);
ne = curr;
new = curr;

while (new && new->prev)
{

if (new->n < new->prev->n)
{
curr = new->prev;

swap(&(curr), list);

print_list(*list);
new = curr->next;
}
new = new->prev;
}
}
ne = ne->next;
}
}


/**
* swap - swap tow nodes of doubly linked list
* @node: pointer to the node 
* @list: pointer to doubly linked list
*/

void swap(listint_t **node, listint_t **list)
{
listint_t *tmp = *node, *tmp2, *tmp3;

if (!(*node)->prev)
*list = (*node)->next;

tmp = tmp3 = *node;
tmp2 = tmp->next;

tmp->next = tmp2->next;
tmp3 = tmp->prev;
tmp->prev = tmp2;
tmp2->next = tmp;
tmp2->prev = tmp3;

if (tmp2->prev)
tmp2->prev->next = tmp2;


if (tmp->next)
tmp->next->prev = tmp;

*node = tmp2;

}
