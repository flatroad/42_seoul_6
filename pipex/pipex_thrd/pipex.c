/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:56 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 05:06:20 by sounchoi         ###   ########.fr       */
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
	envp_path(envp, pipex);
	cmd_path(pipex, argv);
	get_pipe(pipex);
	pipex_exec(pipex, envp);
	close_pipe(pipex, pipex->cmd_count);
	free_pipe(pipex, pipex->cmd_count);
	free_envp(pipex);
	free_cmd_all (pipex);
	close_file(pipex);
	free(pipex);
	pipex = 0;
	system("leaks pipex");
	return (0);
}
