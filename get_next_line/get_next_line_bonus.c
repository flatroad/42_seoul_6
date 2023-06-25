/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:18 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/26 02:20:19 by sounchoi         ###   ########.fr       */
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
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
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

t_dict_node	*find_node(int fd, t_dict *dict)
{
	t_dict_node	*node;

	node = dict->dict_head;
	while (node != NULL)
	{
		if (node->fd == fd)
			return (node);
	}
	node = (t_dict_node *)malloc(sizeof(t_dict_node) * 1);
	if (node == NULL)
		return (node);
	if (dict->dict_end != NULL)
		dict->dict_end->next = node;
	else
		dict->dict_end = node;
	dict->dict_end = node;
	node->next = NULL;
	node->value = (char *)malloc(sizeof(char) * 1);
	if (node->value == NULL)
	{
		free(node);
		node = NULL;
	}
	node->value[0] = 0;
	return (node);
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
