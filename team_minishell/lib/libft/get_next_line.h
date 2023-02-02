/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:15:57 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/02 19:43:49 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

#define BUFFER_SIZE 100
typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	char			*word;
	int				fd;
}	t_node;


t_node	*search_node(int fd, t_node **lst);
char	*get_next_line(int fd);

#endif