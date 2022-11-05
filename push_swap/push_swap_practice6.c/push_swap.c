#include "push_swap.h"

int	push_swap(t_stack *a, t_stack *b, int argc)
{
	if (argc <= 6)
	{
		brute(a, b, argc);
	}
	else
	{
		triangle(a, b, argc);
	}
	return (TRUE);
}

void	triangle(t_stack *a, t_stack *b, int argc)
{
	int	count;
	int	rest;
	
	count = check_handle(argc);
	rest = 0;
	while(count != 0)
	{

		rest = argc % 3;
		argc = argc / 3;
		work(a, b, rest, argc);
		count--;
	}
}

void	work(t_stack *a, t_stack *b, int rest, int quto)
{
	
}


// void	brute_cas3(t_stack *a_stk, t_stack *b_stk, t_list *command)
// {
// 	int	i;

// 	i = 4;
// 	pb(a_stk, b_stk, command);
// 	pb(a_stk, b_stk, command);
// 	brute_cas1(a_stk, command, 0);
// 	brute_cas1(b_stk, command, 1);
// 	while (i--)
// 	{
		
// 	}
// }