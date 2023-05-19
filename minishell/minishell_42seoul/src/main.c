/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:06:31 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:46:09 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

extern int	g_status;

int	main(int argc, char **argv, char **envp)
{
	char				*out;
	t_prompt			prompt;
	t_ref_env			*refer_env;

	if (argc != 1 || argv[1] != NULL)
	{
		write(2, "try again your minishell\n", 26);
		return (1);
	}
	refer_env = make_refer_env(envp);
	while (1)
	{
		signal(SIGINT, sigint_set_readline);
		signal(SIGQUIT, SIG_IGN);
		out = readline("jun_soun@minishell$ ");
		if (!check_args(out, &prompt, refer_env))
			break ;
	}
	exit(g_status);
}
