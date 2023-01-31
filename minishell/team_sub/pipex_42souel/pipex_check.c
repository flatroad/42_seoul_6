/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:45 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:40:24 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_check(int argc, char **argv, t_obj *pipex)
{
	if (len_check(argc, argv, pipex) == 1)
	{
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	if (fd_infile(argv, pipex) == 1)
	{
		unlink("./temp");
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	if (fd_outfile(argc, argv, pipex) == 1)
	{
		unlink("./temp");
		free(pipex);
		pipex = NULL;
		exit(1);
	}
}

int	len_check(int argc, char **argv, t_obj *pipex)
{
	if (argc == 1)
	{
		write(2, "pipex_check error1 : argc is little\n", 35);
		return (1);
	}
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && argv[1][8] == 0)
		pipex->check_doc = 1;
	else
		pipex->check_doc = 0;
	pipex->cmd_start = 2 + pipex->check_doc;
	if (argc - pipex->check_doc < 5)
	{
		write (2, "pipex_check error2 : argc is little\n", 35);
		return (1);
	}
	pipex->cmd_end = argc - 2;
	pipex->cmd_count = pipex->cmd_end - pipex->cmd_start + 1;
	return (0);
}

int	fd_infile(char **argv, t_obj *pipex)
{
	if (pipex->check_doc == 1)
	{
		if (pipex_here_doc(argv[2], pipex) == 1)
			return (1);
	}
	else
	{
		pipex->infile_fd = open(argv[pipex->cmd_start - 1], O_RDONLY);
		if (pipex->infile_fd == -1)
		{
			perror("pipex_check error3 ");
			return (1);
		}
	}
	return (0);
}

int	fd_outfile(int argc, char **argv, t_obj *pipex)
{
	if (pipex->check_doc == 1)
	{
		pipex->outfile_fd = \
		open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->outfile_fd = \
		open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex->outfile_fd == -1)
	{
		perror("pipex_check error4 ");
		close(pipex->infile_fd);
		return (1);
	}
	return (0);
}
