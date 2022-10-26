#include "push_swap.h"

void	init(t_stack *stk)
{
	stk->top = NULL;
	stk->bottom = NULL;
	stk->idx = 0;
}

int	push(t_stack *stk, int data)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node) * 1);
	if(node == NULL)
		return (FALSE);
	node->data = data;
	node->check = stk->idx;
	if (stk->idx == 0)
	{
		node->next = stk->top;
		node->prev = stk->bottom;
		stk->top = node;
		stk->bottom = node;
	}
	else
	{
		stk->top->next = node;
		node->prev = stk->top;
		node->next = NULL;
		stk->top = node;
	}
	return (TRUE);
}
