#include "../minishell.h"
#include "../libft/libft.h"

int	echo(char **str)
{
	if (str == NULL)
		write(1, "\n", 2);
	else
		group_echo(str);
	return (0);
}

void	group_echo(char **str)
{
	int	option;

	option = 2;
	if (str[0][0] == '-')
		option = check_option_echo(str[0]);
	if (option == 1)
		is_op_echo(str);
	else
		not_op_echo(str, option);
}

int	check_option_echo(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 1;
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
	return (2);
}

void	is_op_echo(char	**str)
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
}

void	not_op_echo(char **str, int option)
{
	int	i;

	i = 0;
	if (option == 0)
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
