/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:15:45 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 00:38:06 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*search_node(int fd, t_node **lst)
{
	t_node	*buf;

	if (*lst == NULL)
	{
		*lst = (t_node *)malloc(sizeof(t_node));
		if (*lst == NULL)
			return (NULL);
		(*lst)->fd = fd;
		(*lst)->word = NULL;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		return (*lst);
	}
	buf = *lst;
	while (buf != NULL)
	{
		if (buf->fd == fd)
			break ;
		buf = buf->next;
	}
	return (buf);
}
