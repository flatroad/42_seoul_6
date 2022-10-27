#include "push_swap.h"

int	push_swap_exec(t_stack *a_stk, t_stack *b_stk, char **order, int count)
{
	t_list	*order_list;

	init_order(order_list, count);
	if (count <= 5)
	{
		if (brute_exec(a_stk, order, order_list) == FALSE)
			return (FALSE);
	}
	else
	{
		if (triangle_exec(a_stk, b_stk, order, order_list) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

void	init_order(t_list *list, int count)
{
	list = (t_list *)malloc(sizeof(t_list) * 1);
	list->count = count;
	if (count <= 100)
		list->str = (char **)malloc(sizeof(char *) * 1000);
	else
		list->str = (char **)malloc(sizeof(char *) * 10000);
	list->start = list->str;
	list->next = NULL;
	list->top = -1;
}

int	brute_exec(t_stack *a_stk, char **order, t_list *order_list)
{
	

	


}