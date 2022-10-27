#include "push_swap.h"

int	push_swap(int argc, char **argv, char **order)
{
	t_stack	a_stk;
	t_stack b_stk;
	if(argc == 1)
		return (0);
	init(&a_stk);
	init(&b_stk);

	while(a_stk.idx + 1 < argc)
	{
		printf("argc = %d, a_stk.idx = %d\n", argc, a_stk.idx + 1);
		if (error_check(argv[argc - (a_stk.idx + 1)], &a_stk) == FALSE)
			return (free_stk(&a_stk));
		a_stk.idx = a_stk.idx + 1;
	}
	while(a_stk.top != NULL)
	{
		printf("a_stk.top->data %d, a_stk.top->check %d\n", a_stk.top->data, a_stk.top->check);
		a_stk.top = a_stk.top->prev;
	}
	exit(0);
	if(push_swap_exec(&a_stk, &b_stk, order, argc - 2) == FALSE)
	{
		free_stk(&a_stk);
		free_stk(&b_stk);
		return (FALSE);
	}
	return (TRUE);
}

int	free_stk(t_stack *stk)
{
	t_node	*temp;

	while(stk->top != NULL)
	{
		temp = stk->top;
		stk->top = stk->top->prev;
		free(temp);
		temp = 0;
	}
	stk->bottom = 0;
	return (FALSE);
}

int error_check(char *str, t_stack *stk)
{
	int	data;

	data = 0;
	if (ft_atoi(str, &data) == FALSE)
		return (FALSE);
	if (push(stk, data) == FALSE)
		return (FALSE);
	return (TRUE);
}

