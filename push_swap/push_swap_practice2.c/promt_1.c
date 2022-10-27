#include "push_swap.h"

int	sa(t_stack *a_stk, t_list *order_list)
{
	int	memo;

	memo = a_stk->top->data;
	a_stk->top->data = a_stk->top->prev->data;
	a_stk->top->prev->data = memo;
	if (push_order(order_list, order_list->order[0]) == FALSE)
		return (FALSE);
	return (TRUE)
}

int	sb(t_stack *b_stk, t_list *order_list)
{
	int	memo;

	memo = b_stk->top->data;
	b_stk->top->data = b_stk->top->prev->data;
	b_stk->top->prev->data = memo;
	if (push_order(order_list, order_list->order[1]) == FALSE)
		return (FALSE);
	return (TRUE)
}

int	ss(t_stack *a_stk, t_stack *b_stk, t_list *order_list)
{
	int	memo;

	memo = a_stk->top->data;
	a_stk->top->data = a_stk->top->prev->data;
	a_stk->top->prev->data = memo;
	memo = b_stk->top->data;
	b_stk->top->data = b_stk->top->prev->data;
	b_stk->top->prev->data = memo;
	if (push_order(order_list, order_list->order[2]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	pa(t_stack *a_stk, t_stack *b_stk, t_list *order_list)
{
	t_node	*memo;

	memo = a_stk->top;
	a_stk->top = a_stk->top->prev;
	a_stk->top->next = NULL;
	if (empty_stack(b_stk) == TRUE)
	{	
		b_stk->bottom = memo;
		b_stk->top = memo;
		b_stk->top->prev = NULL;
	}
	else
	{
		b_stk->top->next = memo;
		memo = b_stk->top;
		b_stk->top = b_stk->top->next;
		b_stk->top->prev = memo;
	}
	if (push_order(order_list, order_list->order[3]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	pb(t_stack *a_stk, t_stack *b_stk, t_list *order_list)
{
	t_node	*memo;

	memo = b_stk->top;
	b_stk->top = b_stk->top->prev;
	b_stk->top->next = NULL;
	if (empty_stack(a_stk) == TRUE)
	{	
		a_stk->bottom = memo;
		a_stk->top = memo;
		a_stk->top->prev = NULL;
	}
	else
	{
		a_stk->top->next = memo;
		memo = a_stk->top;
		a_stk->top = a_stk->top->next;
		a_stk->top->prev = memo;
	}
	if (push_order(order_list, order_list->order[4]) == FALSE)
		return (FALSE);
	return (TRUE);
}