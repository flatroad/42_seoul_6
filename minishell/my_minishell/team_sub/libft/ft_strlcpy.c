/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:37:46 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/25 20:30:04 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
	{
		while (src[len] != 0)
			len++;
		return (len);
	}
	while (src[len] != 0 && len < dstsize - 1)
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = 0;
	while (src[len] != 0)
	{
		len++;
	}
	return (len);
}
