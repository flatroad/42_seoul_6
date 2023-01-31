/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:59:47 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:25:24 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex_cmd(t_obj *pipex, char **argv)
{
	pipex->cmd_path = (char ***)malloc(sizeof(char **) * pipex->cmd_count + 1);
	if (pipex->cmd_path == NULL)
	{
		perror("pipex_cmd error1 ");
		pipex_cmd_error(pipex);
	}
	pipex->cmd_path[pipex->cmd_count] = NULL;
	mk_pipex_cmd(pipex, argv);
}

void	mk_pipex_cmd(t_obj *pipex, char **argv)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->cmd_path[i] = ft_split(argv[pipex->cmd_start + i], ' ');
		if (pipex->cmd_path[i] == NULL)
		{
			perror("pipex_cmd error2 ");
			free_cmd(pipex);
			pipex_cmd_error(pipex);
		}
		i++;
	}
}

void	pipex_cmd_error(t_obj *pipex)
{
	free_envp(pipex);
	close_file(pipex);
	free(pipex);
	pipex = NULL;
	exit(1);
}
