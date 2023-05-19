/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:29:12 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:19:00 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_st;
	unsigned char	*src_st;
	size_t			len;

	if (dst == 0 && src == 0)
		return (0);
	dst_st = (unsigned char *)dst;
	src_st = (unsigned char *)src;
	len = 0;
	while (len < n)
	{
		dst_st[len] = src_st[len];
		len++;
	}
	return (dst);
}
