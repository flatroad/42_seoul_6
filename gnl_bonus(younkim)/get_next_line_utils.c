/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 03:16:58 by younkim           #+#    #+#             */
/*   Updated: 2022/02/20 04:01:20 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = -1;
	while (c > 127)
		c -= 128;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[++i])
	{
		if (s[i] == c)
			return ((char *)s + i);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*buf;
	size_t	buf_size;
	size_t	i;

	i = 0;
	buf_size = ft_strlen(s);
	buf = (char *)malloc(sizeof(char) * (buf_size + 1));
	if (buf == NULL)
		return (NULL);
	while (i < buf_size && s[i])
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = 0;
	return (buf);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	size_t	i;
	char	*str;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = (char *)malloc(s1_size + s2_size + 1);
	if (str == NULL)
		return (NULL);
	while (i < s1_size)
		str[i++] = *s1++;
	while (i < s1_size + s2_size)
		str[i++] = *s2++;
	str[i] = 0;
	return (str);
}

t_node	*search_node(int fd, t_node **lst)
{
	t_node	*buf;

	if (*lst == NULL)
	{
		*lst = (t_node *)malloc(sizeof(t_node));
		if (*lst == NULL)
			return (NULL);
		(*lst)->fd = fd;
		(*lst)->word = NULL;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		return (*lst);
	}
	buf = *lst;
	while (buf != NULL)
	{
		if (buf->fd == fd)
			break ;
		buf = buf->next;
	}
	return (buf);
}
