/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:47:39 by choinagi          #+#    #+#             */
/*   Updated: 2022/11/18 13:47:41 by choinagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_split(char **str)
{
	size_t	j;

	j = 0;
	while (str[j] != NULL)
	{
		free(str[j]);
		str[j] = NULL;
		j++;
	}
	free(str);
}

static size_t	split_count(char const *s, char c, size_t s_size)
{
	size_t	i;
	size_t	j;
	char	check;

	i = 0;
	j = 0;
	check = 0;
	while (i < s_size)
	{
		if (s[i] == c)
			check = 0;
		else if (!check)
		{
			check = 1;
			j++;
		}
		i++;
	}
	return (j);
}

static char	*ft_strndup(char const *s, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(n + 1);
	if (!str)
		return (0);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

static char	**ft_split_malloc(char const *s, char c, char **str, size_t s_size)
{
	size_t	i;
	size_t	j;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (i < s_size)
	{
		j = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i + j] && s[i + j] != c)
			j++;
		i += j;
		if (j)
		{
			str[cnt] = ft_strndup(s + (i - j), j);
			if (!str[cnt])
				return (0);
			cnt++;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	s_size;
	size_t	split_count_value;
	char	**str;

	if (!s)
		return (0);
	s_size = ft_strlen(s);
	split_count_value = split_count(s, c, s_size);
	str = (char **)malloc(sizeof(char *) * (split_count_value + 1));
	if (!str)
		return (NULL);
	if (!(ft_split_malloc(s, c, str, s_size)))
	{
		ft_free_split(str);
		return (NULL);
	}
	str[split_count_value] = NULL;
	return (str);
}
