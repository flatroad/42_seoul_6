#include "../../includes/minishell.h"

extern int	g_status;

void	new_exit(char **str)
{
	int	i;
	int	num;

	i = 0;
	while (str[i] != NULL)
		i++;
	if (i == 1)
		new_exit_handle(0, NULL);
	else if (i >= 2)
	{
		if (all_num_check(str[1]) != 0)
			new_exit_handle(2, str[1]);
		if (i > 2)
		{
			new_exit_handle(1, NULL);
			return ;
		}
		num = atoi(str[1]);
		g_status = num % 255;
		exit(g_status);
	}
}

int	all_num_check(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (1);
	while (ft_isdigit(str[i]) == 1)
		i++;
	if (i == len)
		return (0);
	return (1);
}

void	new_exit_handle(int i, char *str)
{
	if (i == 0)
	{
		g_status = 0;
		exit(g_status);
	}
	if (i == 1)
	{
		ft_putendl_fd("Error, new_exit too many arguments", 2);
		g_status = 1;
	}
	if (i == 2)
	{
		ft_putstr_fd("Error, numeric argument required", 2);
		ft_putendl_fd(str, 2);
		g_status = 255;
		exit(g_status);
	}
}
