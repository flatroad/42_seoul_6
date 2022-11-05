#include "push_swap.h"

void	ra(t_stack *a_stk)
{
	t_node	*memo;

	memo = a_stk->top;
	a_stk->top = a_stk->top->prev;
	a_stk->top->next = NULL;
	a_stk->bottom->prev = memo;
	memo->next = a_stk->bottom;
	a_stk->bottom = memo;
	a_stk->bottom->prev = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b_stk)
{
	t_node	*memo;

	memo = b_stk->top;
	b_stk->top = b_stk->top->prev;
	b_stk->top->next = NULL;
	b_stk->bottom->prev = memo;
	memo->next = b_stk->bottom;
	b_stk->bottom = memo;
	b_stk->bottom->prev = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a_stk, t_stack *b_stk)
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
	write(1, "sr\n", 3);
}
