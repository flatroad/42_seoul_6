/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:29:17 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:29:49 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_file(t_obj *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	if (pipex->check_doc == 1)
	{
		if (unlink("./temp") == -1)
		{
			perror("temp file is alive... ");
		}
	}
}

void	close_pipe(t_obj *pipex, int max_i)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < max_i)
	{
		while (j < 2)
		{
			if (close(pipex->fd[i][j]) == -1)
			{
				perror("pipe is not close... ");
			}
			j++;
		}
		i++;
		j = 0;
	}
}
