#include "minishell.h"
#include "./libft/libft.h"

int	find_path(t_fork *fork, t_station *stt)
{
	t_fork	*memo;

	memo = fork;
	while (memo != NULL)
	{
		conf_path(memo->full_cmd[0], memo, stt->env_list);
		if (fork->check == 10)
			return (1);
		memo = memo->next;
	}
	return (0);
}

void	conf_path(char *str, t_fork *fork, t_path_list *path)
{
	if (check_bulitin(str) == 0)
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

char	*ft_strjoin_three(char *str_f, char *str_s, char *str_t)
{
	char	*str;
	char	*str_final;

	str = ft_strjoin(str_f, str_s);
	if (str == NULL)
		return (NULL);
	str_final = ft_strjoin(str, str_t);
	if (str_final == NULL)
	{
		free(str);
		return (NULL);
	}
	return (str_final);
}
