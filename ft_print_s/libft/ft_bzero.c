/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:29:02 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/25 15:29:03 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_st;
	size_t			len;

	s_st = (unsigned char *)s;
	len = 0;
	while (len < n)
	{
		s_st[len] = 0;
		len++;
	}
	return ;
}
