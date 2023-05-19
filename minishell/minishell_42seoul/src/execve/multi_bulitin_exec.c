/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_bulitin_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:06:18 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:03:05 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	exec_multi_bul(t_fork *fok, t_station *stt, int cas)
{
	multi_bulitin(stt, fok, cas);
	g_status = 1;
	exit(g_status);
}

int	multi_bulitin(t_station *stt, t_fork *fok, int cas)
{
	if (cas == 1)
		echo(fok->full_cmd);
	else if (cas == 2)
		cd(fok->full_cmd[1], stt->env_list);
	else if (cas == 3)
		export(fok->full_cmd, stt->env_list);
	else if (cas == 4)
		env(stt->env_list);
	else if (cas == 5)
		pwd();
	else if (cas == 6)
		unset(fok->full_cmd, stt->env_list);
	else if (cas == 7)
		new_exit(fok->full_cmd);
	return (0);
}
