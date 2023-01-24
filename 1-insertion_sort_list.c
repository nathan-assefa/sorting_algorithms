#include "sort.h"
/**
 * * _swap- To swap elements of a list
 * * @list: The main list to be swapped
 * * @tmp: tmporary pointer to list
 */
void _swap(listint_t **list, listint_t *tmp)
{
	listint_t *tmp2;

	if (!tmp->prev->prev)
	{
		(*list)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *list;
		(*list)->prev = tmp;
		tmp->next = *list;
		tmp->prev = NULL;
		*list = tmp;
	}

	else if (tmp->prev->prev && tmp->next)
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->prev->prev->next = tmp;
		tmp->next = tmp->prev;
		tmp->prev = tmp->next->prev;
		tmp->next->prev = tmp;

	}
	else
	{
		tmp2 = tmp->prev;
		tmp2->prev->next = tmp;
		tmp2->next = tmp->next;
		tmp->prev = tmp2->prev;
		tmp2->prev = tmp;
		tmp->next = tmp2;
	}
}

/**
 * * insertion_sort_list - Insertion sort is a simple sorting algorithm
 * * that builds the final sorted array (or list) one item at a time.
 * * @list: Doubly linked list with nodes to sort acording to number n.
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
				_swap(list, aux);
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
