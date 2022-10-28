#include "push_swap.h"


int	rra(t_stack *a_stk, t_list *command)
{
	t_node	*memo;

	memo = a_stk->bottom;
	a_stk->bottom = a_stk->bottom->next;
	a_stk->bottom->prev = NULL;
	a_stk->top->next = memo;
	memo->prev = a_stk->top;
	a_stk->top = memo;
	a_stk->top->next = NULL;
	if (push_cmd(command, command->order->rra) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rrb(t_stack *b_stk, t_list *command)
{
	t_node	*memo;

	memo = b_stk->bottom;
	b_stk->bottom = b_stk->bottom->next;
	b_stk->bottom->prev = NULL;
	b_stk->top->next = memo;
	memo->prev = b_stk->top;
	b_stk->top = memo;
	b_stk->top->next = NULL;
	if (push_cmd(command, command->order->rrb) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	rrr(t_stack *a_stk, t_stack *b_stk, t_list *command)
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
	if (push_cmd(command, command->order->rrr) == FALSE)
		return (FALSE);
	return (TRUE);
}
