/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:03:30 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:17:10 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	cd(char *str, t_envp_list *envp)
{
	int		flag;
	char	path[1024];

	if (getcwd(path, 1024) == NULL)
	{
		ft_putstr_fd("Error, cd: ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_status = 1;
	}
	if (str == NULL)
		flag = go_to_home(envp, path);
	else if (str[0] == 0)
		flag = stay_pwd(envp, path);
	else
		flag = go_to_str(envp, str, path);
	g_status = flag;
}

int	go_to_home(t_envp_list *envp, char *path)
{
	t_envp_list	*list;
	int			i;

	list = envp;
	while (list != NULL)
	{
		i = strlen(list->key);
		if (strncmp(list->key, "HOME", i) == 0)
		{
			if (change_dir(list->value) == 1)
				return (1);
			if (modify_envp(envp, path, list->value) == 1)
				return (1);
			return (0);
		}
		list = list->next;
	}
	return (error_cd("no such HOME"));
}

int	stay_pwd(t_envp_list *envp, char *path)
{
	if (change_dir(path) == 1)
		return (1);
	if (modify_envp(envp, path, path) == 1)
		return (1);
	return (0);
}

int	go_to_str(t_envp_list *envp, char *str, char *old_path)
{
	char	path[1024];

	if (change_dir(str) == 1)
		return (1);
	if (getcwd(path, 1024) == NULL)
		return (error_cd(strerror(errno)));
	if (modify_envp(envp, old_path, path) == 1)
		return (1);
	return (0);
}
