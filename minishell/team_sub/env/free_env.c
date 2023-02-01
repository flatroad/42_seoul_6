#include "../minishell.h"
#include "../libft/libft.h"

t_refer_env	*free_refer_env(int flag, t_refer_env *refer_env)
{
	if (flag == 0)
		write(2, "Error, refer_env malloc fail\n", 30);
	else
		free(refer_env);
	return (NULL);
}

void	free_envp(int flag, t_envp_list *start)
{
	t_envp_list	*memo;

	if (flag == 0)
		write(2, "Error, envp malloc fail..\n", 27);
	while (start != NULL)
	{
		if (start->key != NULL)
			free(start->key);
		if (start->value != NULL)
			free(start->value);
		memo = start;
		start = start->next;
		free(memo);
	}
}

void	free_path(int flag, t_path_list *path)
{
	t_path_list	*memo;

	if (flag == 0)
		write(2, "Error, path_list malloc fail\n", 30);
	while (path != NULL)
	{
		memo = path;
		path = path->next;
		free(memo);
	}
}

void	free_envp_path(char	**path)
{
	int	i;

	i = 0;
	while (path[i] != 0)
	{
		free(path[i]);
		i++;
	}
	free(path);
}
