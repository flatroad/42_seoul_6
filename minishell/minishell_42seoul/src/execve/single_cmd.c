/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:06:26 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:07:30 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	single_cmd(t_station *stt)
{
	int	check;

	if (stt->fok->check != 0 && stt->fok->check != 9)
		return (sglcmd_error_handle(stt->fok->check, stt->fok));
	check = check_bulitin(stt->fok);
	if (check == 8)
	{
		if (stt->fok->check != 4)
			g_status = 0;
		return (0);
	}
	if (check != 0)
		single_bulitin(stt, check);
	else
		exec_single_cmd(stt);
	return (0);
}

int	exec_single_cmd(t_station *stt)
{
	int	pip[2];
	int	pid;

	if (pipe(pip) == -1)
		sglcmd_error_handle(0, stt->fok);
	pid = fork();
	if (pid < 0)
	{
		close(pip[0]);
		close(pip[1]);
		return (sglcmd_error_handle(3, stt->fok));
	}
	else if (pid == 0)
		single_fork(stt, stt->fok->full_path, stt->fok->full_cmd, pip);
	close(pip[1]);
	if (stt->fok->next && stt->fok->next->infile == 0)
		stt->fok->next->infile = pip[0];
	else
		close(pip[0]);
	if (stt->fok->infile > 2)
		close(stt->fok->infile);
	if (stt->fok->outfile > 2)
		close(stt->fok->outfile);
	return (0);
}

int	set_dup(t_station *stt, int pip[2])
{
	if (stt->fok->infile != 0)
	{
		if (dup2(stt->fok->infile, 0) == -1)
			return (sglcmd_error_handle(4, stt->fok));
		close(stt->fok->infile);
	}
	if (stt->fok->outfile != 1)
	{
		if (dup2(stt->fok->outfile, 1) == -1)
			return (sglcmd_error_handle(4, stt->fok));
		close(stt->fok->outfile);
	}
	else if (stt->fok->next && dup2(pip[1], 1) == -1)
		return (sglcmd_error_handle(4, stt->fok));
	return (0);
}
