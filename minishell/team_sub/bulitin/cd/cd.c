#include "../../minishell.h"
#include "../../libft/libft.h"

int	cd(char *str, t_refer_env *refer_env)
{
	int		flag;
	char	path[1024];
	
	if (getcwd(path, 1024) == NULL)
	{
		ft_putstr_fd("Error, ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (1);
	}
	if (str == NULL)
		flag = go_to_home(refer_env, path);
	else if (str[0] == 0)
		flag = stay_pwd(refer_env, path);
	else
		flag = go_to_str(refer_env, str, path);
	return (flag);
}

int	go_to_home(t_refer_env *refer_env, char *path)
{
	t_envp_list	*list;
	int			i;

	list = refer_env->envp;
	while (list != NULL)
	{
		i = strlen(list->key);
		if (strncmp(list->key, "HOME", i) == 0)
		{
			if(change_dir(list->value, refer_env) == 1)
				return (1);
			if (modify_envp(refer_env, path, list->value) == 1)
				return (1);
			return (0);
		}
		list = list->next;
	}
	return (error_cd("no such HOME"));
}

int	stay_pwd(t_refer_env *refer_env, char *path)
{
	t_envp_list	*list;
	int			i;

	if (change_dir(path, refer_env) == 1)
		return (1);
	if (modify_envp(refer_env, path, path) == 1)
		return (1);
	return (0);
}

int	go_to_str(t_refer_env *refer_env, char *str, char *old_path)
{
	char	path[1024];

	if(change_dir(str, refer_env) == 1)
		return (1);
	if(getcwd(path, 1024) == NULL)
		return (error_cd(strerror(errno)));
	if (modify_envp(refer_env, old_path, path) == 1)
		return (1);
	return (0);
}
