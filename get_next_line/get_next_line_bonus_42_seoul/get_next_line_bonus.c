/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:55:59 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/29 22:44:04 by sounchoi         ###   ########.fr       */
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
		dict->dict_head = NULL;
		dict->find_node = find_node;
		dict->out_value = out_value;
		dict->destory_node = destory_node;
		dict->self_check = self_check;
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	value = dict->out_value(fd, dict);
	if (value != NULL && ft_strbox(2, value, '\n') == 0)
		value = read_fd(fd, value);
	if (value == NULL)
		return (NULL);
	out_str = out_put(fd, value, &dict);
	return (out_str);
}

void	self_check(t_dict **dict)
{
	if ((*dict)->dict_head == NULL)
	{
		free(*dict);
		(*dict) = NULL;
	}
}

void	destory_node(int fd, t_dict **dict)
{
	t_dict_node	*node;
	t_dict_node	*node_sv;

	node_sv = (*dict)->dict_head;
	if (node_sv->fd == fd)
	{
		(*dict)->dict_head = node_sv->next;
		free(node_sv);
	}
	else
	{
		while (node_sv->next != NULL)
		{
			node = node_sv->next;
			if (node->fd == fd)
			{
				node_sv->next = node->next;
				free(node);
				break ;
			}
			node_sv = node_sv->next;
		}
	}
	(*dict)->self_check(dict);
}

char	*out_value(int fd, t_dict *dict)
{
	t_dict_node	*node;
	t_dict_node	*node_sv;

	node = dict->find_node(fd, dict);
	if (node != NULL)
		return (node->value);
	node = (t_dict_node *)malloc(sizeof(t_dict_node) * 1);
	if (node == NULL)
		return (NULL);
	node->fd = fd;
	node->next = NULL;
	node->value = (char *)malloc(sizeof(char) * 1);
	if (node->value == NULL)
		return (free(node), NULL);
	node->value[0] = 0;
	if (dict->dict_head == NULL)
		dict->dict_head = node;
	else
	{
		node_sv = dict->dict_head;
		while (node_sv->next != NULL)
			node_sv = node_sv->next;
		node_sv->next = node;
	}
	return (node->value);
}

t_dict_node	*find_node(int fd, t_dict *dict)
{
	t_dict_node	*node;

	node = dict->dict_head;
	while (node != NULL && node->fd != fd)
		node = node->next;
	if (node != NULL)
		return (node);
	return (NULL);
}
