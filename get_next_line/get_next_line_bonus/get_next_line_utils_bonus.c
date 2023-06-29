/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:18 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/29 09:02:08 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line_bonus(int fd)
{
	static t_dict	*dict = NULL;
	char			*value;
	char			*out_str;
	
	if (dict == NULL)
	{
		dict = (t_dict *)malloc(sizeof(t_dict) * 1);
		if (dict == NULL)
			return (NULL);
		dict->dict_free = dict_free;
		dict->find_node = find_node;
		dict->out_value = out_value;
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return ((char *)dict_free(dict));
	value = dict->out_value(fd, dict);
	if (value == NULL)
		return (NULL);
	if (ft_strbox(2, value, '\n') == 0)
		value = read_fd(fd, value);
	if (value == NULL)
		return (NULL);
	out_str = out_put(fd, value, dict);
	if (out_str == NULL)
		return (NULL);
	return (out_str);
}

char	*out_value(int fd, t_dict *dict)
{
	t_dict_node *node;

	node = dict->find_node(fd, dict);
	if (node != NULL)
		return (node->value);
	node = (t_dict_node *)malloc(sizeof(t_dict_node) * 1);
	if (node == NULL)
		return (NULL);
	node->value = (char *)malloc(sizeof(char) * 1);
	if (node->value == NULL)
	{
		free(node);
		return (NULL);
	}
	node->fd = fd;
	if (dict->dict_head == NULL)
		dict->dict_head = node;
	if (dict->dict_end == NULL)
		dict->dict_end = node;
	else
	{
		dict->dict_end->next = node;
		dict->dict_end = dict->dict_end->next;
	}
	dict->dict_end->next = NULL;
	return (dict->dict_end->value);
}

t_dict_node	*find_node(int fd, t_dict *dict)
{
	t_dict_node	*node;

	node = dict->dict_head;
	while (node != NULL && node->fd != fd)
		node = node->next;
	if (node != NULL)
		return (node);
	node = (t_dict_node *)malloc(sizeof(t_dict_node) * 1);
	if (node == NULL)
		return (node);
	node->fd = fd;
	if (dict->dict_head == NULL)
		dict->dict_head = node;
	if (dict->dict_end != NULL)
		dict->dict_end->next = node;
	dict->dict_end = node;
	node->next = NULL;
	node->value = (char *)malloc(sizeof(char) * 1);
	if (node->value == NULL)
	{
		free(node);
		return (node);
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
