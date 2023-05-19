/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_bulitin_exec.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:06:23 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:06:23 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	single_bulitin(t_station *stt, int check)
{
	if (check == 1)
		s_echo(stt->fok->full_cmd, stt->fok->outfile);
	else if (check == 2)
		cd(stt->fok->full_cmd[1], stt->env_list);
	else if (check == 3)
		s_export(stt->fok->full_cmd, stt->env_list, stt->fok->outfile);
	else if (check == 4)
		s_env(stt->env_list, stt->fok->outfile);
	else if (check == 5)
		s_pwd(stt->fok->outfile);
	else if (check == 6)
		unset(stt->fok->full_cmd, stt->env_list);
	else if (check == 7)
	{
		ft_putendl_fd("exit", 2);
		new_exit(stt->fok->full_cmd);
	}
	return (0);
}
