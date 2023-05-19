/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:41:39 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:18:40 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_st;
	unsigned char	c_st;
	size_t			len;

	s_st = (unsigned char *)s;
	c_st = (unsigned char)c;
	len = 0;
	while (len < n)
	{
		if (s_st[len] == c_st)
			return (&(s_st[len]));
		len++;
	}
	return (0);
}
