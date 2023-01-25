/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:31 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 05:00:21 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_envp(char **envp, t_obj *pipex)
{
	while (ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	*envp = *envp + 5;
	pipex->env_path = ft_split(*envp, ':');
	if (pipex->env_path == NULL)
	{
		perror("envp_path error1 ");
		envp_error(pipex);
	}
	tr_envp_path(pipex);
}

void	tr_envp_path(t_obj *pipex)
{	
	int		i;
	char	*save_adr;

	i = 0;
	while (pipex->env_path[i] != NULL)
	{
		save_adr = pipex->env_path[i];
		pipex->env_path[i] = ft_strjoin(pipex->env_path[i], "/");
		if (pipex->env_path[i] == NULL)
		{
			perror("envp_path error2 ");
			pipex->env_path[i] = save_adr;
			free_envp(pipex);
			envp_error(pipex);
		}
		free(save_adr);
		i++;
	}
}

void	envp_error(t_obj *pipex)
{
	close_file(pipex);
	free(pipex);
	pipex = NULL;
	exit(1);
}
