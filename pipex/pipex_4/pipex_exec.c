/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:18:27 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 03:50:15 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_exec(t_obj *pipex, char **envp)
{
	int	i;

	i = 0;
	mk_fd_pipe(pipex);
	while (i < pipex->cmd_count)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
		{
			perror("pipex_exec_ch error1 ");
			close_pipe(pipex, pipex->cmd_count);
			pipex_exec_error_ch(pipex);
		}
		else if (pipex->pid == 0)
			pipex_exec_ch(pipex, envp, i);
		else
			i++;
	}
	wait(NULL);
}

void	mk_fd_pipe(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		if (pipe(pipex->fd[i]) == -1)
		{
			perror("pipex_exec error1 ");
			close_pipe(pipex, i);
			pipex_exec_error(pipex);
		}
		i++;
	}
}

void	pipex_exec_error(t_obj *pipex)
{
	free_pipe(pipex, pipex->cmd_count);
	free_cmd(pipex);
	free_envp(pipex);
	close_file(pipex);
	free(pipex);
	pipex = NULL;
	exit(1);
}
