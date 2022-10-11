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
	int		i;

	i = 0;
	pipex = (t_obj *)malloc(sizeof(t_obj) * 1);
	pipex_check(argc, argv, pipex);	//인자값이 유효한지를 확인 
	envp_path(envp, pipex);			// 환경변수 설정.	
	cmd_path(pipex, argv);			//cmd 명령어 정리
	get_pipe(pipex);					//파이프 생성.	

	pipex_exec(pipex);
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
