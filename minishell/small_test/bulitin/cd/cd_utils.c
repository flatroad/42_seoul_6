#include "../../minishell.h"
#include "../../libft/libft.h"

int	modify_envp(t_refer_env *refer_env, char *path, char *s)
{
	t_envp_list	*list;
	int			i;
	int			count;

	list = refer_env->envp;
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

int	change_dir(char *home, t_refer_env *refer_env)
{
	int	ans;

	ans = chdir(home);
	if (ans != 0)
		return (error_cd(strerror(errno)));
	return (0);
}

int	error_cd(char *s)
{
	ft_putstr_fd("Error, ", 2);
	ft_putendl_fd(s, 2);
	return (1);
}
