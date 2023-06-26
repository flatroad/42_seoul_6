/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 13:08:18 by younkim           #+#    #+#             */
/*   Updated: 2023/06/26 14:49:35 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_node	*next_line(t_node **fd_node, t_node **lst)
{
	char	*tmp;

	tmp = (*fd_node)->word;
	if ((*fd_node) == NULL || (*fd_node)->word == NULL)
		return (NULL);
	if (ft_strchr((*fd_node)->word, '\n'))
		(*fd_node)->word = ft_strdup(ft_strchr((*fd_node)->word, '\n') + 1);
	else
		(*fd_node)->word = ft_strdup("");
	if (ft_strlen((*fd_node)->word) == 0)
	{
		if ((*fd_node)->prev != NULL)
			(*fd_node)->prev->next = (*fd_node)->next;
		if ((*fd_node)->next != NULL)
			(*fd_node)->next->prev = (*fd_node)->prev;
		free((*fd_node)->word);
		if (*lst == (*fd_node))
			*lst = (*lst)->next;
		free((*fd_node));
		(*fd_node) = NULL;
	}
	free(tmp);
	tmp = NULL;
	return ((*fd_node));
}

static char	*ret_line(char *return_line, t_node **fd_node, t_node **lst)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*fd_node)->word[i] && (*fd_node)->word[i] != '\n')
		i++;
	if ((*fd_node)->word[i] == '\n')
		i++;
	return_line = (char *)malloc(i + 1);
	if (return_line == NULL)
		return (NULL);
	while (j < i)
	{
		return_line[j] = (*fd_node)->word[j];
		j++;
	}
	return_line[j] = 0;
	*fd_node = next_line(fd_node, lst);
	return (return_line);
}

static ssize_t	read_line(int fd, t_node *fd_node)
{
	ssize_t	read_value;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return (-1);
	read_value = 1;
	while (read_value != 0)
	{
		tmp = fd_node->word;
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1 || read_value == 0)
			break ;
		buf[read_value] = 0;
		fd_node->word = ft_strjoin(fd_node->word, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(fd_node->word, '\n'))
			break ;
	}
	free(buf);
	return (read_value);
}

static t_node	*create_node(int fd, t_node **lst)
{
	t_node	*buf;
	t_node	*tmp;

	buf = search_node(fd, lst);
	if (buf != NULL)
		return (buf);
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	buf = (t_node *)malloc(sizeof(t_node));
	if (buf == NULL)
		return (NULL);
	buf->fd = fd;
	buf->word = NULL;
	buf->next = NULL;
	buf->prev = tmp;
	tmp->next = buf;
	return (buf);
}

char	*get_next_line(int fd)
{
	static t_node	*lst = NULL;
	char			*return_line;
	t_node			*fd_node;
	ssize_t			read_value;

	return_line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	fd_node = create_node(fd, &lst);
	if (fd_node == NULL)
		return (NULL);
	read_value = read_line(fd, fd_node);
	if (read_value == -1 || (read_value == 0 && fd_node->word == NULL))
	{
		if (fd_node->prev != NULL)
			fd_node->prev->next = fd_node->next;
			fd_node->next->prev = fd_node->prev;
		if (lst == fd_node)
			lst = lst->next;
		free(fd_node);
		return (NULL);
	}
	return_line = ret_line(return_line, &fd_node, &lst);
	return (return_line);
}
