#include "../../includes/minishell.h"

extern int g_status;

int	modify_envp(t_envp_list *envp, char *path, char *s)
{
	t_envp_list	*list;
	int			i;
	int			count;

	list = envp;
	i = 0;
	count = 0;
	while (list != NULL)
	{
		i = strlen (list->key);	
		if (change_pwd(list, s, i, &count) == 1)
				return (1);
		if (change_oldpwd(list, path, i, &count) == 1)
				return (1);
		if (count == 2)
			return (0);
		list = list->next;
	}
	return (error_cd("Error, envp is wrong"));
}

int	change_pwd(t_envp_list *list, char *s, int i, int *count)
{
	char	*save;

	if (strncmp(list->key, "PWD", i) == 0)
	{
		(*count)++;
		save = list->value;
		list->value = ft_strdup(s);
		if (list->value == NULL)
		{
			list->value = save;
			return (error_cd(strerror(errno)));
		}
		free(save);
	}
	return (0);
}

int	change_oldpwd(t_envp_list *list, char *s, int i, int *count)
{
	char	*save;

	if (strncmp(list->key, "OLDPWD", i) == 0)
	{
		(*count)++;
		save = list->value;
		list->value = ft_strdup(s);
		if (list->value == NULL)
		{
			list->value = save;
			return (error_cd(strerror(errno)));
		}
		free(save);
	}
	return (0);
}

int	change_dir(char *str)
{
	int	ans;

	ans = chdir(str);
	if (ans != 0)
		return (error_cd(strerror(errno)));
	return (0);
}

int	error_cd(char *s)
{
	ft_putstr_fd("Error, cd: ", 2);
	ft_putendl_fd(s, 2);
	g_status = 1;
	return (1);
}
