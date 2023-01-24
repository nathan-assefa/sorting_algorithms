#include "sort.h"
/**
 * * _swap - swaps a node at the beggining of the list
 * * @list: Doubly linked list with nodes to sort acording to number n.
 * * @aux: auxiliar node to compare
 */
void _swap(listint_t **list, listint_t *aux)
{
	if (!aux->prev->prev)
	{
		aux->prev->next = aux->next;
		if (aux->next)
			aux->next->prev = aux->prev;
		aux->next = aux->prev;
		aux->prev = aux->prev->prev;
		aux->next->prev = aux;
		*list = aux;
	}
	else if (aux->prev->prev && aux->next)
	{
		aux->prev->next = aux->next;
		aux->next->prev = aux->prev;
		aux->prev->prev->next = aux;
		aux->next = aux->prev;
		aux->prev = aux->next->prev;
		aux->next->prev = aux;
	}
	else if (!aux->next)
	{
		aux->prev->next = aux->next;
		aux->next = aux->prev;
		aux->prev->prev->next = aux;
		aux->prev = aux->next->prev;
		aux->next->prev = aux;
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
