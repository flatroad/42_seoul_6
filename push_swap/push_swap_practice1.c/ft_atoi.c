#include "push_swap.h"

int	ft_atoi(int *data, char *str)
{
	int		sign;
	size_t	num;
	int		i;

	sign = 1;
	num = 0;
	i = 0;
	while ('-' == *str || '+' == *str)
	{
		if(i == 1)
			return (FALSE);
		i = 1;
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (sign * (*str - 48));
		str++;
	}
	while ()
	return (num);
}

int check(char *str, int num, )
{
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (sign * (*str - 48));
		str++;
	}
}