/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:18 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/26 17:58:16 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line_bonus(int fd)
{
	static t_dict	*dict = NULL;
	char			*value;

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
		read_out.read_buf = read_fd(node->fd, node->value);
	else
		read_out.read_buf = no_read_fd(node->value);
	if (read_out.read_buf == NULL)
		return (NULL);
	read_out.out_buf = out_put(read_out.read_buf);
	node->value = save_put(read_out.read_buf);
	free(read_out.read_buf);
	printf("fd : %d, dict : %p\n", fd, dict);
	return (read_out.out_buf);
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
	return (dict->dict_end);
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
		if (flag < 0)
			continue ;
		read_ln[flag] = 0;
		if (ft_strbox(2, (const char *)read_ln, '\n') != 0)
			flag = -1;
		save_buf = ft_strjoin(save_buf, read_ln);
		free(free_buf);
		if (save_buf == 0)
			return (0);
	}
	return (save_buf);
}

char	*no_read_fd(char *save_buf)
{
	char	*read_buf;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strbox(1, save_buf, 0);
	read_buf = (char *)malloc(len + 1);
	if (read_buf == 0)
		return (0);
	read_buf[len] = 0;
	while (i < len)
	{
		read_buf[i] = save_buf[i];
		i++;
	}
	printf("12312312 %p\n", save_buf);
	free(save_buf);
	return (read_buf);
}

char	*out_put(char *read_buf)
{
	char	*out_line;
	size_t	len;
	size_t	idx;

	len = 0;
	idx = 0;
	while (read_buf[len] != 0 && read_buf[len] != '\n')
		len++;
	if (read_buf[len] == '\n')
		len++;
	if (len == 0)
		return (0);
	out_line = malloc(sizeof(char) * (len + 1));
	if (out_line == 0)
		return (0);
	out_line[len] = 0;
	while (idx < len)
	{
		out_line[idx] = read_buf[idx];
		idx++;
	}
	return (out_line);
}

char	*save_put(char *read_buf)
{
	char	*save_put;
	size_t	len;
	size_t	idx;

	len = 0;
	idx = 0;
	while (read_buf[len] != 0 && read_buf[len] != '\n')
		len++;
	if (read_buf[len] == '\n')
		len++;
	if (len == 0)
		return (0);
	while (read_buf[len + idx] != 0)
		idx++;
	save_put = malloc(sizeof(char) * (len + 1));
	if (save_put == 0)
		return (0);
	save_put[len] = 0;
	idx = 0;
	while (read_buf[len + idx] != 0)
	{
		save_put[idx] = read_buf[len + idx];
		idx++;
	}
	return (save_put);
}
