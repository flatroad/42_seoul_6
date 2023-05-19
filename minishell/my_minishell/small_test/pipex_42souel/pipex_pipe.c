/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:40 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:28:56 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_pipe(t_obj *pipex)
{
	pipex->fd = (int **)malloc(sizeof(int *) * pipex->cmd_count);
	if (pipex->fd == NULL)
	{
		perror("get_pipe error1 ");
		get_pipe_error(pipex);
	}
	mk_pipex_pipe(pipex);
}

void	mk_pipex_pipe(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (pipex->fd[i] == NULL)
		{
			perror("get_pipe error2 ");
			free_pipe(pipex, i);
			get_pipe_error(pipex);
		}
		i++;
	}
}

void	get_pipe_error(t_obj *pipex)
{
	free_cmd(pipex);
	free_envp(pipex);
	close_file(pipex);
	free(pipex);
	pipex = NULL;
	exit(1);
}
