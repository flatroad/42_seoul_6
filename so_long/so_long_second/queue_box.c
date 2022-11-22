#include "so_long.h"

void push_queue(t_queue *que, t_error_sb errors, int i, int j)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node) * 1);
	node->next = NULL;
	if (node == NULL)
		error_handle_sb(1, errors);
	node->x_y[0] = i;
	node->x_y[1] = j;
	node->next = NULL;
	que->count++;
	if (que->first == NULL)
	{
		que->first = node;
		que->last = node;
	}
	else
	{
		que->last->next = node;
		que->last = node;
	}
}

void pop_queue(t_queue *que)
{
	t_node	*memo;

	que->count--;
	memo = que->first;
	que->first = que->first->next;
	memo->next = NULL;
	free(memo);
	memo = 0;
}
