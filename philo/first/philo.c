#include "philo.h"

void	philo(int argc, char **argv)
{
	t_inform	inform;

	if(check_param(argc, argv) == 0)
		return (1);
}

int	check_param(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_str(argv[i]) == 1)
			i++;
		else
			return (0);
	}`
	return (1);
}

int	check_str(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len && ft_isdigit(str[i]) == 1)
		i++;
	if (i == len)
		return (1);
	else
		return (0);

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
		return (1);
	}
	return (0);
}
