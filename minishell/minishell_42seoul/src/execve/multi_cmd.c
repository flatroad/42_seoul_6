/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:18:31 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:20:34 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	multi_cmd(t_station *stt)
{
	t_fork	*obj;

	obj = stt->fok;
	while (obj != NULL)
	{
		start_multi_cmd(obj, stt);
		obj = obj->next;
	}
	return (0);
}

void	start_multi_cmd(t_fork *fok, t_station *stt)
{
	int	pip[2];
	int	i;

	i = 0;
	if (pipe(pip) == -1)
		mulcmd_error_handle(0, fok);
	if (fok->check != 0 && fok->check != 9)
	{
		close (pip[0]);
		close (pip[1]);
		mulcmd_error_handle(fok->check, fok);
		return ;
	}
	if (fok->next == NULL)
		i = 1;
	start_multi_fork(fok, stt, pip, i);
}

void	start_multi_fork(t_fork *fok, t_station *stt, int pip[2], int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(pip[0]);
		close(pip[1]);
		mulcmd_error_handle(3, fok);
		return ;
	}
	else if (pid == 0)
		check_multi_case(fok, stt, pip, i);
	close(pip[1]);
	if (i == 0 && fok->next->infile == 0)
		fok->next->infile = pip[0];
	else
		close(pip[0]);
	if (fok->infile > 2)
		close(fok->infile);
	if (fok->outfile > 2)
		close(fok->outfile);
}

int	check_multi_case(t_fork *fok, t_station *stt, int pip[2], int i)
{
	int	cas;

	if (set_pipe(fok, pip, i) == 1)
	{
		close(pip[1]);
		close(pip[0]);
		exit(mulcmd_error_handle(4, fok));
	}
	cas = check_bulitin(fok);
	if (cas != 0)
		exec_multi_bul(fok, stt, cas);
	else
		exec_multi_cmd(fok, stt);
	close(pip[1]);
	close(pip[0]);
	exit(0);
}

int	set_pipe(t_fork *fok, int pip[2], int i)
{
	if (fok->infile != 0)
	{
		if (dup2(fok->infile, 0) == -1)
			return (1);
		close(fok->infile);
	}
	if (fok->outfile != 1)
	{
		if (dup2(fok->outfile, 1) == -1)
			return (1);
		close(fok->outfile);
	}
	else if (i == 0 && dup2(pip[1], 1) == -1)
		return (1);
	close(pip[1]);
	close(pip[0]);
	return (0);
}