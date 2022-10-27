#include "push_swap.h"

int	push_swap_exec(t_stack *a_stk, t_stack *b_stk, char **order, int count)
{
	t_list	*order_list;

	if(init_order(order_list, count, order) == FALSE)
		return (FALSE);
	if (count <= 6)
	{
		brute_exec(a_stk, b_stk, order_list);
		if (check_same(a_stk) == FALSE)
			return (FALSE);
	}
	else
	{
		if (triangle_exec(a_stk, b_stk, order, order_list) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

int	triangle_exec(a_stk, b_stk, order, order_list)
{
	
}

int	init_order(t_list *list, int count, char **order)
{
	list = (t_list *)malloc(sizeof(t_list) * 1);
	if (list == NULL)
		return (FALSE);
	list->count = count;
	if (count <= 10)
		list->max = 100;
	else if (count <= 100)
		list->max = 1000;
	else
		list->max = 10000;
	list->str = (char **)malloc(sizeof(char *) * list->max + 1);
	if (list->str == NULL)
	{
		free(list);
		list = 0;
		return (FALSE);
	}
	list->str[list->max] = 0;
	list->start = list->str;
	list->next = NULL;
	list->order = order;
	list->top = -1;
}

void	brute_exec(t_stack *a_stk, t_stack *b_stk, t_list *order_list)
{
	if (order_list->count == 1)
	 	return ;
	else if (order_list->count == 2)
		brute_2(a_stk, order_list, 0);
	else if (order_list->count == 3)
		brute_3(a_stk, order_list, 0);
	else if (order_list->count == 4)
		brute_4(a_stk, b_stk, order_list);
	else if (order_list->count == 5)
		brute_5(a_stk, b_stk, order_list);
	else
		brute_6(a_stk, b_stk, order_list);
}

void brute_2(t_stack *stk, t_list *order_list, int i)
{
	if (i == 0)
	{
		if (stk->top->data < stk->top->prev->data)
			sa(stk, order_list);
	}
	else
	{
		if (stk->top->data > stk->top->prev->data)
			sb(stk, order_list);
	}
	return (TRUE);
}

void	brute_3(t_stack *stk, t_list *order_list, int i)
{
	int	cas;
	int memo;

	cas = 1;
	memo = 0;
	cas = fide_case(stk, i, cas, memo);
	if (i == 0)
	{
		if (cas == 1)
		{
			ra(stk);
			brute_2(stk, order_list, i);
		}
		else if (cas == 2)
		{
			rra(stk);
			brute_2(stk, order_list, i);
		}
		else
			brute_2(stk, order_list, i);
	}
	else
		brute_3b(stk, order_list, cas);
}

void	brute_3b(t_stack *stk, t_list *order_list, int cas)
{
	if (cas == 1)
	{
		rb(stk);
		brute_2(stk, order_list, 1);
	}
	else if (cas == 2)
	{
		rrb(stk);
		brute_2(stk, order_list, 1);
	}
	else
		brute_2(stk, order_list, 1);
}

int	fide_case(t_stack *stk, int i, int cas, int memo)
{
	if (i == 0)
	{
		while (stk->top->prev != NULL)
		{
			memo = stk->top->data;
			stk->top = stk->top->prev;
			if (stk->top->data < memo)
				cas++;
		}
	}
	else
	{
		while (stk->top->prev != NULL)
		{
			memo = stk->top->data;
			stk->top = stk->top->prev;
			if (stk->top->data > memo)
				cas++;
		}
	}
	return (cas);
}
