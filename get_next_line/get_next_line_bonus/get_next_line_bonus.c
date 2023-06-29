/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:18 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/29 09:28:52 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	idx;
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strbox(1, ((char *)s1), 0);
	s2_len = ft_strbox(1, ((char *)s2), 0);
	idx = 0;
	ptr = (char *)malloc(s1_len + s2_len + 1);
	if (ptr == 0)
		return (0);
	ptr[s1_len + s2_len] = 0;
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
	int		idx;

	if (s == NULL)
		return (NULL);
	len_max = len - start;
	idx = start;
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	while (start < len && *(s + start) != 0)
	{
		*dst = *(s + start);
		dst++;
		start++;
	}
	*dst = 0;
	return (dst - len_max);
}



char	*read_fd(int fd, char *save_buf)
{
	int		flag;
	char	read_ln[BUFFER_SIZE + 1];
	char	*free_buf;

	flag = 1;
	while (flag > 0)
	{
		free_buf = save_buf;
		flag = read(fd, read_ln, BUFFER_SIZE);
		read_ln[flag] = 0;
		if (flag < 0)
			continue ;
		read_ln[flag] = 0;
		if (ft_strbox(2, (const char *)read_ln, '\n') != 0)
			flag = -1;
		save_buf = ft_strjoin(save_buf, read_ln);
		free(free_buf);
		if (save_buf == NULL)
			return (NULL);
	}
	return (save_buf);
}


char	*out_put(int fd, char *read_buf, t_dict *dict)
{
	char	*out_line;
	char	*save_buf;
	char	*dict_str;
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
	save_buf = ft_substr(read_buf, len + 1, ft_strbox(1, save_buf, 0));
	dict_str = dict->out_value(fd, dict);
	dict_str = save_buf;
	free(read_buf);
	return (out_line);
}
