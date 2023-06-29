/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:56:05 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/29 21:56:12 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	new_s_len;
	size_t	idx;
	char	*ptr;

	if (s1 == NULL || s2 == NULL)
		return (0);
	new_s_len = ft_strbox(1, ((char *)s1), 0) + ft_strbox(1, ((char *)s2), 0);
	idx = 0;
	ptr = (char *)malloc(new_s_len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[new_s_len] = 0;
	while (s1[idx] != 0)
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	while (*s2 != 0)
		ptr[idx++] = *(s2++);
	return (ptr);
}

size_t	ft_strbox(int i, const char *s, int c)
{
	size_t	len;

	if (i == 1)
	{
		len = 0;
		while (s[len] != 0)
			len++;
		return (len);
	}
	else
	{
		while (*s != 0)
		{
			if (*s == (char)c)
				return (1);
			s++;
		}
		if (c == 0)
			return (1);
		return (0);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_max;
	char	*dst;
	size_t	idx;

	if (s == NULL || start >= len)
		return (NULL);
	len_max = len - start;
	idx = 0;
	dst = (char *)malloc(sizeof(char) * len_max + 1);
	if (dst == NULL)
		return (NULL);
	dst[len_max] = 0;
	while (idx < len_max && s[start] != 0)
	{
		dst[idx] = s[start];
		idx++;
		start++;
	}
	return (dst);
}

char	*read_fd(int fd, char *save_buf)
{
	int		flag;
	char	read_ln[BUFFER_SIZE + 1];
	char	*free_buf;
	int		i;

	flag = 1;
	while (flag > 0)
	{
		while (i < BUFFER_SIZE + 1)
		{
			read_ln[i] = 0;
			i++;
		}
		i = 0;
		free_buf = save_buf;
		if (read(fd, read_ln, BUFFER_SIZE) <= 0)
			break ;
		if (ft_strbox(2, (const char *)read_ln, '\n') == 1)
			flag = -1;
		save_buf = ft_strjoin(save_buf, read_ln);
		free(free_buf);
		if (save_buf == NULL)
			return (NULL);
	}
	return (save_buf);
}

char	*out_put(int fd, char *read_buf, t_dict **dict)
{
	char	*out_line;
	char	*save_buf;
	size_t	len;
	size_t	idx;

	len = 0;
	idx = 0;
	while (read_buf[len] != 0 && read_buf[len] != '\n')
		len++;
	if (read_buf[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	out_line = ft_substr(read_buf, 0, len);
	if (out_line == NULL)
		return (NULL);
	save_buf = ft_substr(read_buf, len, ft_strbox(1, read_buf, 0));
	if (save_buf == NULL)
		(*dict)->destory_node(fd, dict);
	else
		(*dict)->find_node(fd, (*dict))->value = save_buf;
	free(read_buf);
	return (out_line);
}
