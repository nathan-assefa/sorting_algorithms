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
