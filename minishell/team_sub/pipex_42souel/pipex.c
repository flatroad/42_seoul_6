/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:56 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 04:57:28 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_obj	*pipex;

	pipex = (t_obj *)malloc(sizeof(t_obj) * 1);
	if (pipex == NULL)
	{
		perror("main error : ");
		return (1);
	}
	pipex_check(argc, argv, pipex);
	pipex_envp(envp, pipex);
	pipex_cmd(pipex, argv);
	get_pipe(pipex);
	pipex_exec(pipex, envp);
	close_pipe(pipex, pipex->cmd_count);
	free_pipe(pipex, pipex->cmd_count);
	free_cmd(pipex);
	free_envp(pipex);
	close_file(pipex);
	free(pipex);
	pipex = 0;
	return (0);
}
