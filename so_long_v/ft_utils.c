/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 06:28:27 by younkim           #+#    #+#             */
/*   Updated: 2022/07/07 10:56:17 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_error(char *s)
{
	printf("%s\n", s);
	exit(0);
}

void	heap_error(char *s)
{
	printf("%s\n", s);
	exit(1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		s1_size;
	int		s2_size;

	i = -1;
	if (s1 == NULL)
		s1_size = 0;
	else
		s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (ret == NULL)
		return (NULL);
	while (++i < s1_size)
		ret[i] = s1[i];
	while (i < (s1_size + s2_size))
		ret[i++] = *s2++;
	ret[i] = '\0';
	if (s1_size != 0)
		free(s1);
	return (ret);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}	
	return (0);
}
