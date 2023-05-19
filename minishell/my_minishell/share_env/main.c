#include "minishell.h"
#include "./libft/libft.h"

t_refer_env	*make_refer_env(char **envp);
t_envp_list	*make_envp(char **envp);
t_envp_list	*add_envp_list(char *str);
t_path_list *make_path(char **envp);
char		**check_envp(char **envp);
t_path_list	*make_path_list(char **path);
t_path_list	*add_path_list(char *str);
t_refer_env	*free_refer_env(int flag, t_refer_env *refer_env);
void		free_envp(int flag, t_envp_list *start);
void		free_path(int flag, t_path_list *path);
void		free_envp_path(char	**path);

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		return (1);
	}
	if (make_refer_env(envp) == NULL)
		return (1);
	return (0);
}

t_refer_env	*make_refer_env(char **envp)
{
	t_refer_env	*refer_env;

	refer_env = (t_refer_env *)malloc(sizeof(t_refer_env) * 1);
	if (refer_env == NULL)
		return (free_refer_env(0, refer_env));
	if (envp == NULL || envp[0] == NULL)
		return (refer_env);
	refer_env->envp = make_envp(envp);
	if (refer_env->envp == NULL)
		return (free_refer_env(1, refer_env));
	envp = check_envp(envp);
	if (envp == NULL)
		return (refer_env);
	refer_env->path = make_path(envp);
	if (refer_env->path == NULL)
	{	
		free_envp(1, refer_env->envp);
		return (free_refer_env(1, refer_env));
	}
	for(int i = 0; i < 10; i++)
	{
		printf("key %s\n", refer_env->envp->key);
		printf("value %s\n", refer_env->envp->value);
		printf("------------------------------------\n");
		printf("path %s\n", refer_env->path->value);
		printf("------------------------------------\n");
		refer_env->envp = refer_env->envp->next;
		refer_env->path = refer_env->path->next;
	}
	return (refer_env);
}

t_envp_list	*make_envp(char **envp)
{
	t_envp_list *start;
	t_envp_list *memo;
	int			i;

	i = 0;
	memo = add_envp_list(envp[i]);
	if (memo == NULL)
		return (NULL);
	start = memo;
	i++;
	while (envp[i] != NULL)
	{
		memo->next = add_envp_list(envp[i]);
		if (memo->next == NULL)
		{
			free_envp(0, start);
			return (NULL);
		}
		memo = memo->next;
		i++;
	}
	return (start);
}

t_envp_list	*add_envp_list(char *str)
{
	int			i;
	t_envp_list	*add;

	i = 0;
	add = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (add == NULL)
		return (NULL);
	while (str[i] != '=')
		i++;
	add->key = ft_substr(str, 0, i);
	if (add->key == NULL)
		return (NULL);
	add->value = ft_substr(str, i + 1, ft_strlen(str + i + 1));
	if (add->value == NULL)
		return (NULL);
	add->next = NULL;
	return (add);
}


char	**check_envp(char **envp)
{
	while (strncmp("PATH=", *envp, 5) != 0 && envp != NULL)
		envp++;
	if (envp == NULL)
		return (NULL);
	else
	{
		*envp = *envp + 5;
		return (envp);
	}
}

t_path_list *make_path(char **envp)
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
