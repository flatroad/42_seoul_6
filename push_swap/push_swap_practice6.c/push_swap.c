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
	int	(*fp[2][2][3])(t_stack, t_stack, int, int);
	int rl;

	init_fp(fp);
	rl = 1;
	while (1)
	{
		if (argc <= 3)
		{
			final_cut(a, b, argc);
			break;
		}
		argc = fp[rl][argc % 2][a, b, argc / 3, argc % 3];
		rl = -rl;
	}
}

void	init_fp(int	(*fp[2][2][3])(t_stack, t_stack, int, int))
{
	fp[0][0][0] = left1;
	fp[0][0][1] = left3;
	fp[0][0][2] = left3;
	fp[0][1][0] = left2;
	fp[0][1][1] = left3;
	fp[0][1][2] = left3;
	fp[1][0][0] = right1;
	fp[1][0][1] = right3;
	fp[1][0][2] = right3;
	fp[1][1][0] = right2;
	fp[1][1][1] = right3;
	fp[1][1][2] = right3;
}

int	left1(t_stack *a, t_stack *b, int quto, int rest)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < quto)
	{
		if(a->top->data != count)
		{
			count = a->top->data;
			i++;
		}
		pa(a, b);
	}
	calc(a, b, quto, rest);
	return (quto);
}

void	calc(t_stack *a, t_stack *b, int quto, int rest)
{
	
}

int	left2(t_stack *a, t_stack *b, int quto, int rest)
{
	return (quto + 1);
}

int	left3(t_stack *a, t_stack *b, int quto, int rest)
{
	return (quto + 1);
}

int right1(t_stack *a, t_stack *b, int quto, int rest)
{
	return (quto);
}

int	right2(t_stack *a, t_stack *b, int quto, int rest)
{
	return (quto + 1);
}

int right3(t_stack *a, t_stack *b, int quto, int rest)
{
	return (quto + 1);
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