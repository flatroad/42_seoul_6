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

void	brute(t_stack *a, t_stack *b, int argc, t_list *command)
{
	if (argc == 1)
		return ;
	if (argc == 2)
		brute_cas1(a, command, 0);
	if (argc == 3)
		brute_cas2(a, command, 0);
	if (b != 0)
		b = 0;
}

void	brute_cas1(t_stack *stk, t_list *command, int i)
{
	if (i == 0)
	{
		if(stk->top->data < stk->top->prev->data)
			sa(stk, command);
	}
	else
	{
		if(stk->top->data > stk->top->prev->data)
			sb(stk, command);
	}
}

void	brute_cas2(t_stack *stk, t_list *command, int i)
{
	int flag;
	
	flag = fide_stk(stk->top, i);
	if (i == 0)
	{
		if (flag == 1)
		{
			ra(stk, command);
			brute_cas1(stk, command, i);
		}
		else if (flag== 2)
		{
			rra(stk, command);
			brute_cas1(stk, command, i);
		}
		else
			brute_cas1(stk, command, i);
	}
	// else
	// 	brute_cas2b(stk, command, i, flag);
}

int	fide_stk(t_node *stk, int i)
{
	int	flag;
	int	memo;

	flag = 1;
	if (i == 0)
	{
		while (stk->prev != NULL)
		{
			memo = stk->data;
			stk = stk->prev;
			if (stk->data < memo)
				flag++;
		}
	}
	else
	{
		while (stk->prev != NULL)
		{
			memo = stk->data;
			stk = stk->prev;
			if (stk->data > memo)
				flag++;
		}
	}
	return (flag);
}
