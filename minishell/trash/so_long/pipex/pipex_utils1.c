/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:50 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/14 05:10:12 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (s1[len] != s2[len])
			return ((unsigned char)s1[len] - (unsigned char)s2[len]);
		if (s1[len] == 0 && s2[len] == 0)
			return (0);
		len++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ptr == 0)
		return (0);
	ptr = ft_memmove(ptr, s1, s1_len);
	ptr = ft_memmove((ptr + s1_len), s2, s2_len);
	ptr = (ptr - s1_len);
	ptr[s1_len + s2_len] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

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
