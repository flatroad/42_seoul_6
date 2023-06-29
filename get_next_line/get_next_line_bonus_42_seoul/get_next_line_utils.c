/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:49:12 by sounchoi          #+#    #+#             */
/*   Updated: 2022/08/24 12:09:15 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	idx = 0;
	ptr = (char *)ft_calloc(1, (s1_len + s2_len + 1));
	if (ptr == 0)
		return (0);
	while (s1[idx] != 0)
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	while (*s2 != 0)
		ptr[idx++] = *(s2++);
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}
