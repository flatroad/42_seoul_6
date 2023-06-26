/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:18 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/26 17:59:09 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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



t_dict_node	*dict_free(t_dict *dict)
{
	t_dict_node	*memo;

	if (dict == NULL)
		return (NULL);
	while (dict->dict_head != NULL)
	{
		if (dict->dict_head->value != NULL)
			free(dict->dict_head->value);
		memo = dict->dict_head;
		dict->dict_head = dict->dict_head->next;
		free(memo);
	}
	free(dict);
	dict = NULL;
	return (NULL);
}
