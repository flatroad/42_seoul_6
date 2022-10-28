#include "push_swap.h"

int	ra(t_stack *a_stk, t_list *command)
{
	t_node	*memo;

	memo = a_stk->top;
	a_stk->top = a_stk->top->prev;
	a_stk->top->next = NULL;
	a_stk->bottom->prev = memo;
	memo->next = a_stk->bottom;
	a_stk->bottom = memo;
	a_stk->bottom->prev = NULL;
	if (push_cmd(command, command->order->ra) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rb(t_stack *b_stk, t_list *command)
{
	t_node	*memo;

	memo = b_stk->top;
	b_stk->top = b_stk->top->prev;
	b_stk->top->next = NULL;
	b_stk->bottom->prev = memo;
	memo->next = b_stk->bottom;
	b_stk->bottom = memo;
	b_stk->bottom->prev = NULL;
	if (push_cmd(command, command->order->rb) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rr(t_stack *a_stk, t_stack *b_stk, t_list *command)
{
	t_node	*memo;

	memo = a_stk->top;
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
	if (push_cmd(command, command->order->rr) == FALSE)
		return (FALSE);
	return (TRUE);
}
