/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:35:37 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:18:50 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_st;
	unsigned char	*s2_st;
	size_t			len;

	s1_st = (unsigned char *)s1;
	s2_st = (unsigned char *)s2;
	len = 0;
	while (len < n)
	{
		if (s1_st[len] != s2_st[len])
			return (s1_st[len] - s2_st[len]);
		len++;
	}
	return (0);
}
