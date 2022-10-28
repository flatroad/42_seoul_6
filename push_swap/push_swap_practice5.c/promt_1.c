#include "push_swap.h"

int	sa(t_stack *a_stk, t_list *command)
{
	int	memo;

	memo = a_stk->top->data;
	a_stk->top->data = a_stk->top->prev->data;
	a_stk->top->prev->data = memo;
	if (push_cmd(command, command->order->sa) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	sb(t_stack *b_stk, t_list *command)
{
	int	memo;

	memo = b_stk->top->data;
	b_stk->top->data = b_stk->top->prev->data;
	b_stk->top->prev->data = memo;
	if (push_cmd(command, command->order->sb) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ss(t_stack *a_stk, t_stack *b_stk, t_list *command)
{
	int	memo;

	memo = a_stk->top->data;
	a_stk->top->data = a_stk->top->prev->data;
	a_stk->top->prev->data = memo;
	memo = b_stk->top->data;
	b_stk->top->data = b_stk->top->prev->data;
	b_stk->top->prev->data = memo;
	if (push_cmd(command, command->order->ss) == FALSE)
		return (FALSE);
	return (TRUE);
}
