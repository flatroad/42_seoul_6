/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 05:29:20 by younkim           #+#    #+#             */
/*   Updated: 2022/07/07 10:54:05 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	split_cnt(char *s, char c)
{
	int	i;
	int	flag;
	int	ret;

	i = 0;
	flag = 0;
	ret = 1;
	while (s[i])
	{
		if (flag == 1 && s[i] != c)
		{
			ret++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (ret);
}

static char	*split_malloc(char *s, int start, int end)
{
	char	*ret;
	int		i;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (end - start + 1));
	if (ret == NULL)
		heap_error("Error : malloc");
	while (start < end)
	{
		ret[i++] = s[start];
		start++;
	}
	ret[i] = '\0';
	return (ret);
}

static char	**push_char(char *s, char c, char **ret, int cnt)
{
	int	start;
	int	end;
	int	ret_index;
	int	i;

	ret_index = 0;
	i = 0;
	end = 0;
	while (ret_index < cnt)
	{
		start = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		end = i;
		ret[ret_index++] = split_malloc(s, start, end);
		while (s[i] != '\0' && s[i] == c)
			i++;
	}
	return (ret);
}

char	**ft_split(char *s, char c)
{
	char	**ret;
	int		cnt;
	int		ret_index;

	if (c == '\0')
		return (NULL);
	cnt = split_cnt(s, c);
	ret_index = 0;
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ret == NULL)
		heap_error("Error : malloc");
	ret[cnt] = NULL;
	ret = push_char(s, c, ret, cnt);
	return (ret);
}

char	**read_split(int fd)
{
	char	tmp[MAX_READ + 1];
	char	**map;
	char	*ret;
	ssize_t	read_size;

	read_size = 1;
	ret = NULL;
	while (read_size)
	{
		read_size = read(fd, tmp, MAX_READ);
		if (read_size == 0)
			break ;
		tmp[read_size] = 0;
		ret = ft_strjoin(ret, tmp);
	}
	if (ret == NULL && read_size == 0)
		file_error("Error\nMap : Not text");
	map = ft_split(ret, '\n');
	free(ret);
	ret = NULL;
	return (map);
}
