/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:18:37 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:03:06 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	single_fork(t_station *stt, char *path, char **cmd, int pip[2])
{
	char	**envp;

	envp = tran_envp(stt->env_list);
	if (envp == NULL)
		write(2, "read the envp is fail..\n", 25);
	if (set_dup(stt, pip) != 0)
		sglcmd_error_handle(4, stt->fok);
	execve(path, cmd, envp);
	sglcmd_error_handle(5, stt->fok);
	g_status = 1;
	exit(g_status);
}
