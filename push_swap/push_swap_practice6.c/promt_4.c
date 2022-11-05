#include "push_swap.h"


void	rra(t_stack *a_stk)
{
	t_node	*memo;

	memo = a_stk->bottom;
	a_stk->bottom = a_stk->bottom->next;
	a_stk->bottom->prev = NULL;
	a_stk->top->next = memo;
	memo->prev = a_stk->top;
	a_stk->top = memo;
	a_stk->top->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b_stk)
{
	t_node	*memo;

	memo = b_stk->bottom;
	b_stk->bottom = b_stk->bottom->next;
	b_stk->bottom->prev = NULL;
	b_stk->top->next = memo;
	memo->prev = b_stk->top;
	b_stk->top = memo;
	b_stk->top->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a_stk, t_stack *b_stk)
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
	write(1, "rrr\n", 4);
}
