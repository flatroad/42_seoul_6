#include "push_swap.h"

int	push_swap(t_stack *a, t_stack *b, int argc, t_list *command)
{
	if (argc <= 6)
	{
		brute(a, b, argc, command);
	}
	// else
	// {
	// 	triangle(a, b, argc, command);
	// }
	return (TRUE);
	
}

void	brute_cas3(t_stack *a_stk, t_stack *b_stk, t_list *command)
{
	int	i;

	i = 4;
	pb(a_stk, b_stk, command);
	pb(a_stk, b_stk, command);
	brute_cas1(a_stk, command, 0);
	brute_cas1(b_stk, command, 1);
	while (i--)
	{
		
	}
}