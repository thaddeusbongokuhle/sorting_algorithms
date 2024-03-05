#include "sort.h"

/**
 * swap_from_right - swap items of a list from right
 * @i: current item address
 * @list: list
 *
 * Return: void
 */
void swap_from_right(listint_t **i, listint_t **list)
{
	listint_t *a = (*i)->prev;

	while (a)
	{
		if (a->next && a->n > a->next->n)
		{
			listint_t *prev_a = a->prev;
			listint_t *next_b = NULL;
			listint_t *b = a->next;

			if (a->next)
			{
				next_b = a->next->next;
				next_b->prev = a;
			}

			if (prev_a)
				prev_a->next = b;
			else
				*list = b;

			b->next = a;
			a->next = next_b;
			a->prev = b;
			b->prev = prev_a;

			print_list(*list);
		}

		a = a->prev;
	}
}

/**
 * swap - swap items of a list
 * @list: list to change
 *
 * Return:_ void
 */
void swap(listint_t **list)
{
	listint_t **i = list;

	while ((*i)->next)
	{
		if ((*i)->n > (*i)->next->n)
		{
			listint_t *next_b = (*i)->next->next;
			listint_t *prev_a = (*i)->prev;

			listint_t *tmp = *i;
			*i = (*i)->next;
			*(&(*i)->next) = tmp;

			(*i)->next->next = next_b;
			(*i)->next->prev = *i;
			(*i)->prev = prev_a;

			if (next_b)
				next_b->prev = (*i)->next;

			print_list(*list);
		}

		i = (&(*i)->next);
	}

	swap_from_right(i, list);
}

/**
 * cocktail_sort_list - sort list by cocktail sort method
 * @list: list to change
 *
 * Rerturn: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp_loop = NULL;

	if (list == NULL || !(*list) || (*list)->next == NULL)
		return;

	tmp_loop = *list;

	while (tmp_loop)
	{
		swap(list);
		tmp_loop = tmp_loop->next;
	}
}
