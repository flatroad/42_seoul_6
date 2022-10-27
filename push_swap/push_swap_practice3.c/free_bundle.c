#include "push_swap.h"

void	free_all(t_stack *a_stk, t_stack *b_stk, t_list *command)
{
	free_stack(a_stk);
	free_stack(b_stk);

}

void	free_stack(t_stack *stk)
{
	t_node	*memo;

	while(stk->top != NULL)
	{
		memo = stk->top;
		stk->top = stk->top->prev;
		memo->next = 0;
		memo->prev = 0;
		free(memo);
	}
	stk->bottom = 0;
}

void	free_list(t_list *command)
{
	while( != 0)
	{

	}
}