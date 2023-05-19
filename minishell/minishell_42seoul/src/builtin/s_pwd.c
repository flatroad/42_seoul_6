/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pwd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:04:48 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:17:45 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

void	s_pwd(int fd)
{
	char	path[1024];

	if (getcwd(path, 1024) == NULL)
	{
		ft_putstr_fd("Error, ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_status = 1;
	}
	ft_putendl_fd(path, fd);
	g_status = 0;
}
