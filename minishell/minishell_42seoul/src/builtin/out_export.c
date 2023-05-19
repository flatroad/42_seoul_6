/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:05:10 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:05:10 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	out_export(t_envp_list *envp)
{
	t_envp_list	*memo;

	memo = envp;
	while (memo != NULL)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(memo->key, 1);
		if (memo->value != NULL)
		{
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(memo->value, 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd("\n", 1);
		}
		else
			ft_putchar_fd('\n', 1);
		memo = memo->next;
	}
}
