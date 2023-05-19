/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:02:55 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 04:22:26 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	sigint_set_readline(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	sig_exec(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 128 + SIGINT;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	if (sig == SIGQUIT)
	{
		g_status = 128 + SIGQUIT;
		ft_putstr_fd("Quit: \n", STDOUT_FILENO);
	}
}
