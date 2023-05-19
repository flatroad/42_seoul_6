/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:18:41 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:14:03 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	exec_multi_cmd(t_fork *fok, t_station *stt)
{
	char	**envp;

	envp = tran_envp(stt->env_list);
	if (envp == NULL)
		write(2, "read the envp is fail..\n", 25);
	execve(&fok->full_path[0], fok->full_cmd, envp);
	mulcmd_error_handle(5, fok);
	if (access(stt->fok->full_path, F_OK) == 0)
	{
		g_status = 127;
		if (access(stt->fok->full_path, X_OK) == -1)
			g_status = 126;
	}
	else
		g_status = 1;
	exit(g_status);
}
