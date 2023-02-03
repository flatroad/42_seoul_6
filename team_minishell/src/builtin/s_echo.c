#include "../../includes/minishell.h"

extern int	g_status;

void	s_echo(char **str, int fd)
{
	if (str[1] == NULL)
		write(fd, "\n", 2);
	else
		s_group_echo(str, fd);
	g_status = 0;
}

void	s_group_echo(char **str, int fd)
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
	if (i != 1)
		s_is_op_echo(str, i, fd);
	else
		s_not_op_echo(str, fd);
}

int	s_check_option_echo(char *str)
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
	return (0);
}

void	s_is_op_echo(char	**str, int i, int fd)
{
	while (str[i] != NULL)
	{
		ft_putstr_fd(str[i], fd);
		if (str[i + 1] != NULL)
			ft_putchar_fd(' ', fd);
		i++;
	}
}

void	s_not_op_echo(char **str, int fd)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		ft_putstr_fd(str[i], fd);
		if (str[i + 1] != NULL)
			ft_putchar_fd(' ', fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
