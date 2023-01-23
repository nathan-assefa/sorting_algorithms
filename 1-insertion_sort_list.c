#include "sort.h"

/**
 * * _swap- To swap elements of a list
 * * @list: The main list to be swapped
 * * @aux: tmporary pointer to list
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
	else
	{
		aux->prev->next = aux->next;
		aux->next = aux->prev;
		aux->prev->prev->next = aux;
		aux->prev = aux->next->prev;
		aux->next->prev = aux;
	}
}

/**
 * * insertion_sort_list- Insertion sorting
 * * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *head = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (; head; head = head->next)
	{
		tmp = head;

		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				_swap(list, tmp);
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}

/**
 * * swap- To swap two numbers
 * * @a: the first number to be swapped
 * * @b: the second number to be swapped
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
