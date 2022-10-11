/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pipe_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:12:55 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 00:15:04 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
