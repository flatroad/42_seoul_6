#include "push_swap.h"

int	push_swap(t_stack a, t_stack b, int argc, t_list command)
{
	if (argc <= 6)
	{
		brute(a, b, argc, command);
	}
	else
	{
		triangle(a, b, argc, command);
	}
	
}

void	brute(t_stack a, t_stack b, int argc, t_list command)
{
	if (argc == 1)
		return ;
	if (argc == 2)
	{
		
	}
}