#include "push_swap.h"

void	brute(t_stack *a, t_stack *b, int argc, t_list *command)
{
	if (argc == 1)
		return ;
	else if (argc == 2)
		brute_cas1(a, command, 0);
	else if (argc == 3)
		brute_cas2(a, command, 0);
	else if (argc == 4)
		brute_cas3(a, b, command);
	else if (argc == 5)
		brute_cas4(a, b, command);
	else
		brute_cas5(a, b ,command);
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
	else
		brute_cas2b(stk, command, i, flag);
}

void	brute_cas2b(t_stack *stk, t_list *command, int i, int flag)
{
	if (flag == 1)
	{
		rb(stk, command);
		brute_cas1(stk, command, i);
	}
	else if (flag== 2)
	{
		rrb(stk, command);
		brute_cas1(stk, command, i);
	}
	else
		brute_cas1(stk, command, i);
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
