/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:40 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 00:20:33 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_pipe(t_obj *pipex)
{
	make_pipe1(pipex);
	make_pipe2(pipex);
}

void	make_pipe1(t_obj *pipex)
{
	pipex->fd = (int **)malloc(sizeof(int *) * pipex->cmd_count);
	if (pipex->fd == NULL)
	{
		perror("error_check9 ");
		free_cmd_all(pipex);
		free_envp(pipex);
		close_file(pipex);
		free(pipex);
		pipex = NULL;
		exit(1);
	}
}

void	make_pipe2(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (pipex->fd[i] == NULL)
		{
			perror("error_check9 ");
			free_pipe(pipex, i);
			free_cmd_all(pipex);
			free_envp(pipex);
			close_file(pipex);
			free(pipex);
			pipex = NULL;
			exit(1);
		}
		i++;
	}
}
