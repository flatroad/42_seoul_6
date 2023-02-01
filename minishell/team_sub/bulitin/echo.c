#include "../minishell.h"
#include "../libft/libft.h"

int	echo(char **str)
{
	if (str[1] == NULL)
		write(1, "\n", 2);
	else
		group_echo(str);
	return (0);
}

void	group_echo(char **str)
{
	int	option;
	int	i;

	i = 1;
	option = 2;
	while (str[i] != NULL && str[i][0] == '-')
	{
		option = check_option_echo(str[i]);
		if (option == 0)
			break ;
		i++;
	}
	if (i != 0)
		is_op_echo(str, i);
	else
		not_op_echo(str);
}

int	check_option_echo(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	while (str[i] != 0)
	{
		if (str[i] != 'n')
			break ;
		i++;
	}
	if (len == 1)
		return (0);
	if (len == i)
		return (1);
	return (0);
}

void	is_op_echo(char	**str, int i)
{
	i++;
	while (str[i] != NULL)
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
}

void	not_op_echo(char **str)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1] != NULL)
			ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}
