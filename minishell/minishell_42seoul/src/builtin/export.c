/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:03:35 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:17:18 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	export(char **exp_str, t_envp_list *envp)
{
	t_envp_list	*exp;

	if (exp_str[1] == NULL)
	{
		out_export(envp);
		g_status = 0;
		return ;
	}
	exp = make_exp(exp_str);
	if (exp == NULL)
	{
		write(2, "Error, export malloc fail..\n", 26);
		g_status = 1;
	}
	if (output_exp(exp, envp) == 1)
	{
		write(2, "error, envp malloc fail..\n", 32);
		free_exp(exp);
		g_status = 1;
	}
	free_exp(exp);
	g_status = 0;
}
