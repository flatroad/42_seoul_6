/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_exec_ch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:51:10 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:47:58 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_exec_ch(t_obj *pipex, char **envp, int i)
{
	if (make_dup(pipex, i) == 1)
	{
		perror("pipex_exec_ch error1 ");
		pipex_exec_error_ch(pipex);
	}
	close_pipe(pipex, pipex->cmd_count);
	tr_pipex_ch1(pipex, envp, i);
	tr_pipex_ch2(pipex, envp, i);
	write(2, "pipex_exec_ch error2 ; : lastpoint_error\n", 41);
	exit(1);
}

void	tr_pipex_ch1(t_obj *pipex, char **envp, int i)
{
	if (access(pipex->cmd_path[i][0], F_OK) != -1)
	{
		if (execve(pipex->cmd_path[i][0], pipex->cmd_path[i], envp) == -1)
		{
			perror("pipex_exec_ch error3 ");
			pipex_exec_error_ch(pipex);
		}
	}
}

void	tr_pipex_ch2(t_obj *pipex, char **envp, int i)
{
	char	*str;
	int		idx;

	idx = 0;
	while (pipex->env_path[idx] != 0)
	{
		str = ft_strjoin(pipex->env_path[idx], pipex->cmd_path[i][0]);
		if (str == NULL)
		{
			perror("pipex_exec_ch error4 ");
			pipex_exec_error_ch(pipex);
		}
		if (access(str, F_OK) == -1)
			free(str);
		else
		{
			if (execve(str, pipex->cmd_path[i], envp) == -1)
			{
				perror("pipex_exec_ch error5 ");
				free(str);
				pipex_exec_error_ch(pipex);
			}
		}
		idx++;
	}
}

int	make_dup(t_obj *pipex, int i)
{
	if (i <= 0)
	{
		if (dup2(pipex->infile_fd, 0) == -1 || dup2(pipex->fd[i][1], 1) == -1)
		{
			return (1);
		}
	}
	else if (i > 0 && i < pipex->cmd_count - 1)
	{
		if (dup2(pipex->fd[i - 1][0], 0) == -1 || \
		dup2(pipex->fd[i][1], 1) == -1)
		{
			return (1);
		}
	}
	else
	{
		if (dup2(pipex->fd[i - 1][0], 0) == -1 || \
		dup2(pipex->outfile_fd, 1) == -1)
		{
			return (1);
		}
	}
	return (0);
}

void	pipex_exec_error_ch(t_obj *pipex)
{
	free_pipe(pipex, pipex->cmd_count);
	free_cmd(pipex);
	free_envp(pipex);
	close_file(pipex);
	free(pipex);
	pipex = NULL;
	exit(1);
}
