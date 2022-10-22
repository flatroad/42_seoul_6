#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	num;
	int		i;

	sign = 1;
	num = 0;
	while ((9 <= *str && *str <= 14) || *str == ' ')
		str++;
	if (i = 0 && ('-' == *str || '+' == *str))
	{
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
	return (num);
}

int check(char *str, int num, )
{
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (sign * (*str - 48));
		str++;
	}
	while ((9 <= *str && *str <= 14) || *str == ' ')
		str++;
}