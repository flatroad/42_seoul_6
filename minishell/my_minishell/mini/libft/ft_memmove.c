/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:57:15 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:19:08 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_st;
	unsigned char	*src_st;
	size_t			count;

	if (dst == src)
		return (dst);
	dst_st = (unsigned char *)dst;
	src_st = (unsigned char *)src;
	count = 0;
	if (dst > src)
	{
		while (count < len)
		{
			dst_st[len - count - 1] = src_st[len - count - 1];
			count++;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
