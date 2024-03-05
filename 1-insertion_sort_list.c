#include "sort.h"


/**
 * swap1 - sort and array
 * @tprev: node prev
 * @tnext: node next
 * Return: no return
 */
void swap1(listint_t *tprev, listint_t *tnext)
{
	if (tprev->prev)
		tprev->prev->next = tnext;
	if (tnext->next)
		tnext->next->prev = tprev;
	tprev->next = tnext->next;
	tnext->prev = tprev->prev;
	tprev->prev = tnext;
	tnext->next = tprev;
}

/**
 * swap2 - sort and array
 * @tnext: node prev
 * @tprev: node next
 * Return: no return
 */
void swap2(listint_t *tnext, listint_t *tprev)
{

	if (tnext->prev)
		tnext->prev->next = tprev;
	if (tprev->next)
		tprev->next->prev = tnext;
	tnext->next = tprev->next;
	tprev->prev = tnext->prev;
	tnext->prev = tprev;
	tprev->next = tnext;
}

/**
 * swap3 - sort and array
 * @tnext: node prev
 * @tprev: node next
 * @list: head liked list
 * Return: no return
 */
void swap3(listint_t **list, listint_t *tprev, listint_t *tnext)
{
	if (!tnext->next)
	{
		tprev->prev = tnext;
		tnext->next = tprev;
		tnext->prev = NULL;
		tprev->next = NULL;
		*list = tnext;
		print_list(*list);
	} else
	{
		tnext->next->prev = tprev;
		tprev->next = tnext->next;
		tprev->prev = tnext;
		tnext->next = tprev;
		tnext->prev = NULL;
		if (!tnext->prev)
			*list = tnext;
	}
}

/**
 * insertion_sort_list - sort and array
 * @list: head of the double linked list
 * Return: no return
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tnext = NULL, *tprev = NULL, *temp2 = NULL;
	int count = 0, flag = 0;

	if (list == NULL || *list == NULL || !*list || !list || !(*list)->next)
		return;
	tnext = (*list)->next, tprev = *list, temp2 = *list;
	while (tnext)
	{
		if (count == 0)
		{
			if (tprev->n > tnext->n)
			{
				if (!tnext->next)
				{
					swap3(list, tprev, tnext);
					break; }
				swap3(list, tprev, tnext), print_list(*list), flag = 1; } }
		while (tprev)
		{
			if (tprev->n > tnext->n && flag == 0)
			{ temp2 = tprev, swap1(tprev, tnext);
				if (!tnext->prev)
				{ *list = tnext;
					print_list(*list);
					break; }
				print_list(*list);
				tnext = tnext->prev, tprev = tprev->prev, flag = 1; } else
				break;
			if (tnext->n > tprev->n && flag == 1)
			{ swap2(tnext, tprev);
				if (!tprev->prev)
				{ *list = tprev, print_list(*list);
					break; }
				print_list(*list);
				tprev = tprev->prev, tnext = tnext->prev, flag = 0; } else
				break; }
		if (temp2->next)
		{ temp2 = temp2->next, tnext = temp2, tprev = temp2->prev, count = count + 1;
			flag = 0; } else
			break; } }
