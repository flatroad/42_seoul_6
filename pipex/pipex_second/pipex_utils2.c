/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:53 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/12 10:39:25 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// split 함수
size_t	ft_mk_size(char *s, char c)
{
	size_t	size;
	int		flag;

	size = 0;
	flag = 1;
	while (*s != 0)
	{
		if (*s == c)
			flag = 1;
		else
		{
			if (flag == 1)
				size++;
			flag = 0 ;
		}
		s++;
	}
	return (size);
}

char	**free_array(char **str_array, size_t idx)
{
	while (idx == 0)
	{
		idx--;
		free(str_array[idx]);
		str_array[idx] = 0;
	}
	free(str_array);
	str_array = 0;
	return (str_array);
}

char	**ft_mk_array(char **str_array, char *s, size_t size, char c)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = 0;
	while (idx < size)
	{
		while (*s == c)
			s++;
		while (*s != c && *s != 0)
		{
			s++;
			len++;
		}
		str_array[idx] = (char *)malloc(sizeof(char) * len + 1);
		if (str_array[idx] == 0)
		{
			str_array = free_array(str_array, idx);
			return (0);
		}
		idx++;
	}
	str_array[idx] = NULL;
	return (str_array);
}

void	ft_pull_array(char **str_array, char *s, size_t size, char c)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < size)
	{
		while (*s == c)
			s++;
		while (*s != 0 && *s != c)
		{
			str_array[x][y] = *s;
			s++;
			y++;
		}
		printf("%s\n", str_array[x]);
		printf("%p\n", str_array[x]);
		str_array[x][y] = 0;
		x++;
		y = 0;
	}
	printf("%p\n", str_array[x]);
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**str_array;

	if (s == 0)
		return (0);
	size = ft_mk_size((char *)s, c);
	str_array = (char **)malloc(sizeof(char *) * (size + 1));
	if (str_array == 0)
		return (0);
	str_array = ft_mk_array(str_array, (char *)s, size, c);
	if (str_array == 0)
		return (0);
	ft_pull_array(str_array, (char *)s, size, c);
	return (str_array);
}
