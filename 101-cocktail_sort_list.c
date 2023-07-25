#include "sort.h"

void swap(listint_t **node, listint_t **list);

/**
* cocktail_sort_list - sorts a doubly linked list in ascending order
* @list: pointer to doubly linked list
*/

void cocktail_sort_list(listint_t **list)
{
listint_t *new, *ne;
int x = 1;

ne = NULL;

if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
return;

while (x)
{
new = *list;
x = 0;
while (new->next != NULL)
{
ne = new->next;
if (new->n > ne->n)
{
swap(&new, list);
 print_list(*list);
x = 1;
}
new = new->next;
}
while (new->prev != NULL)
{
ne = new->prev;
if (new->n < ne->n)
{
swap(&ne, list);
print_list(*list);
new = ne->next;
x = 1;
}
new = new->prev;
}
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
