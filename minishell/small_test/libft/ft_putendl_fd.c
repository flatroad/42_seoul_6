/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:19:35 by sounchoi          #+#    #+#             */
/*   Updated: 2023/01/28 01:19:59 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s == 0)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
