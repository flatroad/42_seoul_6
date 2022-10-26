#include "push_swap.h"

int ft_atoi(char *str, int *data)
{
	int		sign;
	size_t	num;
	int		i;
	
	sign = 1;
	num = 0;
	i = 0;
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
