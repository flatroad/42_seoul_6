#include "../minishell.h"
#include "../libft/libft.h"

int	find_path(t_fork *fork, t_station *stt)
{
	t_fork	*memo;

	memo = fork;
	while (memo != NULL)
	{
		if (memo->full_cmd == NULL)
			fork->check = 9;
		else
			conf_path(memo->full_cmd[0], memo, stt->path_list);
		if (fork->check == 10)
		{
			free_find_path(fork);
			free(stt);
			return (1);
		}
		memo = memo->next;
	}
	return (0);
}

void	conf_path(char *str, t_fork *fork, t_path_list *path)
{
	if (check_bulitin(fork) != 0)
		return ;
	if (first_check(str, fork) == 0)
		return ;
	if (second_check(str, fork, path) == 0)
		return ;
}

int	first_check(char *str, t_fork *fork)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, X_OK) == 0)
		{
			fork->check = 0;
			fork->full_path = strdup(str);
			if (fork->full_path == NULL)
				fork->check = 10;
			return (0);
		}
		fork->check = 2;
		return (0);
	}
	fork->check = 1;
	return (1);
}

int	second_check(char *check, t_fork *fork, t_path_list *path)
{
	char		*str;
	t_path_list	*memo;

	memo = path;
	while (memo != NULL)
	{
		str = ft_strjoin_three(memo->value, "/", check);
		if (str == NULL)
		{
			fork->check = 10;
			return (0);
		}
		if (first_check(str, fork) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
		memo = memo->next;
	}
	return (1);
}
