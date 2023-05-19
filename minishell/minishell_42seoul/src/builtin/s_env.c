/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:04:37 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:17:30 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	s_env(t_envp_list *envp, int fd)
{
	t_envp_list	*memo;

	memo = envp;
	while (memo != NULL)
	{
		if (memo->value != NULL)
		{
			ft_putstr_fd(memo->key, fd);
			ft_putstr_fd("=", fd);
			ft_putendl_fd(memo->value, fd);
		}
		memo = memo->next;
	}
	g_status = 0;
}
