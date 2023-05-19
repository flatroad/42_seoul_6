/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:22 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:29:07 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_envp(t_obj *pipex)
{
	int	i;

	i = 0;
	while (pipex->env_path[i] != NULL)
	{
		free(pipex->env_path[i]);
		pipex->env_path[i] = 0;
		i++;
	}
	free(pipex->env_path);
	pipex->env_path = 0;
}

void	free_cmd(t_obj *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pipex->cmd_path[i] != NULL)
	{
		while (pipex->cmd_path[i][j] != NULL)
		{
			free(pipex->cmd_path[i][j]);
			pipex->cmd_path[i][j] = 0;
			j++;
		}
		free(pipex->cmd_path[i]);
		pipex->cmd_path[i] = 0;
		i++;
		j = 0;
	}
	free(pipex->cmd_path);
	pipex->cmd_path = 0;
}

void	free_pipe(t_obj *pipex, int max_i)
{
	int	i;

	i = 0;
	while (i < max_i)
	{
		free(pipex->fd[i]);
		pipex->fd[i] = 0;
		i++;
	}
	free(pipex->fd);
	pipex->fd = 0;
}
