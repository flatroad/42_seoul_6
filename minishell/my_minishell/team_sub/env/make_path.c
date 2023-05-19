#include "../minishell.h"
#include "../libft/libft.h"

t_path_list	*make_path(char **envp)
{
	char		**path;
	t_path_list	*path_list;

	path = ft_split(*envp, ':');
	if (path == NULL)
	{
		write(2, "Error, path split fail..", 25);
		return (NULL);
	}
	path_list = make_path_list(path);
	if (path_list == NULL)
	{
		free_envp_path(path);
		return (NULL);
	}
	free(path);
	return (path_list);
}

t_path_list	*make_path_list(char **path)
{
	t_path_list	*start;
	t_path_list	*memo;
	int			i;

	i = 0;
	memo = add_path_list(path[i]);
	if (memo == NULL)
		return (NULL);
	start = memo;
	i++;
	while (path[i] != 0)
	{
		memo->next = add_path_list(path[i]);
		if (memo->next == NULL)
		{
			free_path(0, start);
			return (NULL);
		}
		memo = memo->next;
		i++;
	}
	return (start);
}

t_path_list	*add_path_list(char *str)
{
	t_path_list	*path;

	path = (t_path_list *)malloc(sizeof(t_path_list) * 1);
	if (path == NULL)
		return (NULL);
	path->value = str;
	path->next = NULL;
	return (path);
}
