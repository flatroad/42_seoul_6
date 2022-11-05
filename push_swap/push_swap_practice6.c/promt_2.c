#include "push_swap.h"

void	pa(t_stack *a_stk, t_stack *b_stk)
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
	write(1, "pa\n", 3);
}

void	pb(t_stack *a_stk, t_stack *b_stk)
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
	write(1, "pb\n", 3);
}
