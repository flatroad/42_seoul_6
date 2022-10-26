#include "push_swap.h"

void	push_swap(int argc, char **argv, char **order)
{
	int	i;
	
	i = 0;
	if (argc <= 1)
		return ;
	t_stack	a_stk;
	t_stack	b_stk;
	init(&a_stk);
	init(&b_stk);
	while(i < argc)
	{
		error_check(i, argv[i], &a_stk);
		i++;
	}
}

void	error_check(int i, char *argv, t_stack *stk)
{
	int data;

	if(ft_atoi(&data, argv) == FALSE)
	{
		
	}



	if (i == 0)
		f_push(stk, i, data);
	else
		push(stk, i, data);
	
}

int		main(int argc, char **argv)
{
	char **order = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

	push_swap(argc, argv, order);
}

// =-------------------------------------------=//
void	init(t_stack *stk)
{
	stk->top = NULL;
	stk->bottom = NULL;
	stk->idx = -1;
}

void	f_push(t_stack *stk, int i, int data)
{
	stk->idx++;
	t_node	*tmp = (t_node *)malloc(sizeof(t_node) * 1);
	tmp->data = data;
	tmp->check = i;
	tmp->prev = stk->bottom;
	tmp->next = stk->top;
	stk->bottom = tmp;
	stk->top = tmp;
}

void push(t_stack *stk, int i, int data)
{
	stk->idx++;
	t_node	*tmp = (t_node *)malloc(sizeof(t_node) * 1);
	tmp->data = data;
	tmp->check = i;
	stk->top->next = tmp;
	tmp->prev = stk->top;
	tmp->next = NULL;
	stk->top = tmp;

}
