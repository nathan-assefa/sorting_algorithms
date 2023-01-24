#include "sort.h"
/**
 * swap_head - swaps a node at the beggining of the list
 * @list: Doubly linked list with nodes to sort acording to number n.
 * @tmp: auxiliar node to compare
 */
void swap_head(listint_t **list, listint_t *tmp)
{
	(*list)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *list;
	(*list)->prev = tmp;
	tmp->next = *list;
	tmp->prev = NULL;
	*list = tmp;
}
/**
 * swap_middle - swaps a node at the middle of the list
 * @tmp: auxiliar node to compare
 */
void swap_middle(listint_t *tmp)
{
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->prev->prev->next = tmp;
	tmp->next = tmp->prev;
	tmp->prev = tmp->next->prev;
	tmp->next->prev = tmp;
}
/**
 * swap_tail - swaps a node at the end of the list
 * @tmp: auxiliar node to compare
 */
void swap_tail(listint_t *tmp)
{
	listint_t *tmp2;

	tmp2 = tmp->prev;
	tmp2->prev->next = tmp;
	tmp2->next = tmp->next;
	tmp->prev = tmp2->prev;
	tmp2->prev = tmp;
	tmp->next = tmp2;
}
/**
 * insertion_sort_list - Insertion sort is a simple sorting algorithm
 * that builds the final sorted array (or list) one item at a time.
 * @list: Doubly linked list with nodes to sort acording to number n.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *aux = NULL;
	int i = 0, j = 0;

	if (!list || !(*list)->next)
		return;
	aux = (*list)->next;
	while (aux)
	{
		i++;
		while (aux->prev)
		{
			if (aux->prev->n > aux->n)
			{
				if (!aux->prev->prev)
					swap_head(list, aux);
				else if (aux->prev->prev && aux->next)
					swap_middle(aux);
				else if (!aux->next)
					swap_tail(aux);
				print_list(*list);
			}
			else
				aux = aux->prev;
		}
		while (j <= i)
		{
			aux = aux->next;
			j++;
		}
		j = 0;
	}
}
