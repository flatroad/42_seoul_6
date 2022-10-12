/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 01:18:27 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 10:37:31 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_exec(t_obj *pipex)
{
	int	i;

	i = 0;
	make_fd_pipe(pipex);
	while (i < pipex->cmd_count)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
		{
			close_pipe(pipex, pipex->cmd_count);
			free_all(pipex);
		}
		else if (pipex->pid == 0)
		{
			if (i == 0)
				pipex_ch1(pipex, i, 0);
			else
				pipex_ch2(pipex, i, 0);
		}
	i++;
	}
	wait(NULL);
}

void	make_fd_pipe(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		if (pipe(pipex->fd[i]) == -1)
		{
			close_pipe(pipex, i);
			free_all(pipex);
		}
		i++;
	}
}

void	pipex_ch1(t_obj *pipex, int i, int idx)
{
	char	*str;

	if (dup2(pipex->infile_fd, 0) == -1)
		exit(1);
	close(pipex->infile_fd);
	if (dup2(pipex->fd[i][1], 1) == -1)
		exit(1);
	close(pipex->fd[0][1]);
	while (pipex->env_path[idx] != 0)
	{
		str = ft_strjoin(pipex->env_path[idx], pipex->cmd_path[i][0]);
		if (str == NULL)
			exit(1);
		if (access(str, F_OK) == -1)
			free(str);
		else
		{
			write(2, "here 1\n", 7);
			if (execve(str, pipex->cmd_path[i], NULL) == -1)
			{
				write(2, "\n123123\n", 9);
				exit(1);
			}
		}
		idx++;
	}
	write(2, "error_check10 : lastpoint_error\n", 33);
	exit(1);
}

void	pipex_ch2(t_obj *pipex, int i, int idx)
{
	char	*str;

	if(dup2(pipex->fd[i - 1][0], 0) == -1)
		write(2, "123\n", 4);
	close(pipex->fd[i][0]);
	if (i < pipex->cmd_count - 1)
	{	
		if(dup2(pipex->fd[i][1], 1) == -1)
			write(2, "123\n", 4);
		close(pipex->fd[i][1]);
	}
	else
	{
		if (dup2(pipex->outfile_fd, 1) == -1)
			write(2, "123\n", 4);
		close(pipex->outfile_fd);
	}

	while (pipex->env_path[idx] != 0)
	{
		str = ft_strjoin(pipex->env_path[idx], pipex->cmd_path[i][0]);
		if (str == 0)
			exit(1);
		if (access(str, F_OK) == -1)
			free(str);
		else
		{
			write(2, "here 2\n", 7);
			write(2, str, strlen(str));
			if (execve(str, pipex->cmd_path[i], NULL) == -1)
			{
				write(2, "here 3\n", 7);
				exit(1);
			}
		}
		idx++;
	}
	write(2, "error_check10 : lastpoint_error\n", 33);
	exit(1);
}
