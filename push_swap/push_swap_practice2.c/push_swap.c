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
		if (error_check(argv[a_stk.idx + 1], &a_stk) == FALSE)
			return (free_stk(&a_stk));
		a_stk.idx = a_stk.idx + 1;
	}
	return (TRUE);
}



int error_check(char *str, t_stack *stk)
{
	int	data;

	data = 0;
	if (ft_atoi(str, &data) == FALSE)
	{
		write(2, "Error\n", 6);
		return (FALSE);
	}
	if (push(stk, data) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	push(t_stack *stk, int data)
{
	if (stk->idx == 0)
	{
		t_node	*node = (t_node *)malloc(sizeof(t_node) * 1);
		node->data = data;
		node->check = stk->idx;
		node->next = 
	}
}

int ft_atoi(char *str, int *data)
{
	int		sign;
	size_t	num;
	int		i;
	
	sign = 1;
	num = 0;
	i = 0;
	printf("str = %s\n", str);
	while ('-' == *str || '+' == *str)
	{
		if (i == 1)
			return (FALSE);
		i = 1;
		if (*str == '-')
			sign = -sign;
		str++;
	}
	if(ft_atoi_n(str, data, sign, &num) == FALSE)
	{
		return (FALSE);
	}
	printf("num == %zu\n", num);
	return (TRUE);
}

int ft_atoi_n(char *str, int *data, int sign, size_t *num)
{
	int	i;

	i = 0;
	while ('0' <= *str && *str <= '9')
	{
		i++;
		*num = ((*num) * 10) + ((*str) - 48);
		str++;
	}
	if (*str == 0)
	{
		if(i == 0)
			return (FALSE);
		else
		{
			if (check_num(num, sign) == FALSE)
				return (FALSE);
			*data = (int)(sign * (*num));
			return (TRUE);
		}
	}
	else
		return (FALSE);
}

int check_num(size_t *num, int sign)
{
	if (sign == -1)
	{
		if(*num > -MIN_INT)
			return (FALSE);
	}
	else
	{
		if(*num > MAX_INT)
			return (FALSE);
	}
	return (TRUE);
}
