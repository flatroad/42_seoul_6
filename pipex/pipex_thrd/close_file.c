/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:33 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 00:01:22 by sounchoi         ###   ########.fr       */
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
			perror("temp file is alive... ");
	}
}
