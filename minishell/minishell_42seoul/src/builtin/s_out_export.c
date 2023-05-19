/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_out_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:03:22 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:03:22 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	s_out_export(t_envp_list *envp, int fd)
{
	t_envp_list	*memo;

	memo = envp;
	while (memo != NULL)
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(memo->key, fd);
		if (memo->value != NULL)
		{
			ft_putstr_fd("=", fd);
			ft_putstr_fd("\"", fd);
			ft_putstr_fd(memo->value, fd);
			ft_putstr_fd("\"", fd);
			ft_putstr_fd("\n", fd);
		}
		else
			ft_putchar_fd('\n', fd);
		memo = memo->next;
	}
}
