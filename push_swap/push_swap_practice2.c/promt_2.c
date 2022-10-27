#include "push_swap.h"

int	ra(t_stack *a_stk, t_list *order_list)
{
	t_node	*memo;

	memo = a_stk->top;
	a_stk->top = a_stk->top->prev;
	a_stk->top->next = NULL;
	a_stk->bottom->prev = memo;
	memo->next = a_stk->bottom;
	a_stk->bottom = memo;
	a_stk->bottom->prev = NULL;
	if (push_order(order_list, order_list->order[5]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rb(t_stack *b_stk, t_list *order_list)
{
	t_node	*memo;

	memo = b_stk->top;
	b_stk->top = b_stk->top->prev;
	b_stk->top->next = NULL;
	b_stk->bottom->prev = memo;
	memo->next = b_stk->bottom;
	b_stk->bottom = memo;
	b_stk->bottom->prev = NULL;
	if (push_order(order_list, order_list->order[6]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rr(t_stack *a_stk, t_stack *b_stk, t_list *order_list)
{
	t_node	*memo;

	a_stk->top = a_stk->top->prev;
	a_stk->top->next = NULL;
	a_stk->bottom->prev = memo;
	memo->next = a_stk->bottom;
	a_stk->bottom = memo;
	a_stk->bottom->prev = NULL;
	memo = b_stk->top;
	b_stk->top = b_stk->top->prev;
	b_stk->top->next = NULL;
	b_stk->bottom->prev = memo;
	memo->next = b_stk->bottom;
	b_stk->bottom = memo;
	b_stk->bottom->prev = NULL;
	if (push_order(order_list, order_list->order[7]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rra(t_stack *a_stk, t_list *order_list)
{
	t_node	*memo;

	memo = a_stk->bottom;
	a_stk->bottom = a_stk->bottom->next;
	a_stk->bottom->prev = NULL;
	a_stk->top->next = memo;
	memo->prev = a_stk->top;
	a_stk->top = memo;
	a_stk->top->next = NULL;
	if (push_order(order_list, order_list->order[8]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rrb(t_stack *b_stk, t_list *order_list)
{
	t_node	*memo;

	memo = b_stk->bottom;
	b_stk->bottom = b_stk->bottom->next;
	b_stk->bottom->prev = NULL;
	b_stk->top->next = memo;
	memo->prev = b_stk->top;
	b_stk->top = memo;
	b_stk->top->next = NULL;
	if (push_order(order_list, order_list->order[9]) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rrr(t_stack *a_stk, t_stack *b_stk, t_list *order_list)
{
	t_node	*memo;

	memo = a_stk->bottom;
	a_stk->bottom = a_stk->bottom->next;
	a_stk->bottom->prev = NULL;
	a_stk->top->next = memo;
	memo->prev = a_stk->top;
	a_stk->top = memo;
	a_stk->top->next = NULL;
	memo = b_stk->bottom;
	b_stk->bottom = b_stk->bottom->next;
	b_stk->bottom->prev = NULL;
	b_stk->top->next = memo;
	memo->prev = b_stk->top;
	b_stk->top = memo;
	b_stk->top->next = NULL;
	if (push_order(order_list, order_list->order[10]) == FALSE)
		return (FALSE);
	return (TRUE);
}
