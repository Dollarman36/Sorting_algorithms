#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                       in ascending order using the Insertion
 *                       sort algorithm.
 *
 * @list: head to a doubly linked list.
 *
 * Return: void
 */


void insertion_sort_list(listint_t **list)
{
	listint_t *node1 = NULL, *node2 = NULL, *t = NULL;

	if (list == NULL)
		return;
	node1 = *list;

	while (node1 != NULL)
	{
		t = node1;
		node2 = node1;
		while (node2->prev != NULL && node2->prev->n > t->n)
			node2 = node2->prev;
		if (node2 != t)
		{
			t->prev->next = t->next;
			if (t->next != NULL)
				t->next->prev = t->prev;
			t->next = node2;
			t->prev = node2->prev; /* Tener en cuenta */
			t->next->prev = t;
			if (t->prev != NULL)
				t->prev->next = t;
			else
				*list = t;
			print_list(*list);
		}
		node1 = node1->next;
	}
}




