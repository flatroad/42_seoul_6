#include "push_swap.h"

void	sa(t_stack *a_stk)
{
	int	memo;

	memo = a_stk->top->data;
	a_stk->top->data = a_stk->top->prev->data;
	a_stk->top->prev->data = memo;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b_stk)
{
	int	memo;

	memo = b_stk->top->data;
	b_stk->top->data = b_stk->top->prev->data;
	b_stk->top->prev->data = memo;
	write(1, "sb\n", 3);
}

void	ss(t_stack *a_stk, t_stack *b_stk)
{
	int	memo;

	memo = a_stk->top->data;
	a_stk->top->data = a_stk->top->prev->data;
	a_stk->top->prev->data = memo;
	memo = b_stk->top->data;
	b_stk->top->data = b_stk->top->prev->data;
	b_stk->top->prev->data = memo;
	write(1, "ss\n", 3);
}
