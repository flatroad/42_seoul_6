#include "philo.h"

int	check_param(int argc, char **argv)
{
	int	i;
	t_error	err;

	i = 1;
	init_error(&err);
	if (5 > argc || 6 < argc)
		return (error_handle(1, err));
	while (i < argc)
	{
		if (check_str(argv[i], err) == SUSSESS)
			i++;
		else
			return (FAIL);
	}
	return (SUSSESS);
}

int	check_str(char *str, t_error err)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len && ft_isdigit(str[i]) == SUSSESS)
		i++;
	if (i != len)
		return (error_handle(2, err));
	return (SUSSESS);

}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
	{
		return (SUSSESS);
	}
	return (FAIL);
}
