#include "push_swap.h"

void	push_swap(int argc, char **argv, char **order)
{
	int	i;

	i = 1;
	a_stack	a_stk;
	b_stack b_stk;
	a_init(&a_stk);
	b_init(&b_stk);
	error_check(int argc, char *argv[i])
}

s_list	*error_check(int argc, char **argv)
{
	if (argc == 1)
		return (NULL);
	
}

int		main(int argc, char **argv)
{
	char **order = {"sa", "sb", "ss", "pa", "pb", \
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

	push_swap(argc, argv, order);
}

// =-------------------------------------------=//
void	a_init(a_stack *a_stk)
{
	a_stk->top = NULL;
	a_stk->bottom = NULL;
}

void	b_init(b_stack *b_stk)
{
	b_stk->top = NULL;
	b_stk->bottom = NULL;
}

void push(a_stack *a_stk, int i)
{
	a_stk->idx++;
	a_node	*tmp = (a_node *)malloc(sizeof(a_node) * 1);
	if(a_stk->idx == 0)
	{
		a_stk->bottom = tmp;
		tmp->before = NULL;
		tmp->data = i;
		tmp->next = NULL;
		tmp->check = 0;
	}
	else
	{
		a_stk->top 
	}

}
