/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:55:52 by sounchoi          #+#    #+#             */
/*   Updated: 2023/06/29 23:05:37 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_dict_node	t_dict_node;
typedef struct s_dict		t_dict;
typedef t_dict_node			*(*t_func_dict2)(int, t_dict *);
typedef char				*(*t_func_dict3)(int, t_dict *);
typedef void				(*t_func_dict4)(int, t_dict **);
typedef void				(*t_func_dict5)(t_dict **);

typedef struct s_dict
{
	t_dict_node		*dict_head;
	t_func_dict2	find_node;
	t_func_dict3	out_value;
	t_func_dict4	destory_node;
	t_func_dict5	self_check;
}	t_dict;

typedef struct s_dict_node
{
	int					fd;
	char				*value;
	struct s_dict_node	*next;
}	t_dict_node;

typedef struct s_read_out
{
	char	*read_buf;
	char	*out_buf;
}	t_read_out;

char		*get_next_line(int fd);
t_dict_node	*find_node(int fd, t_dict *dict);
void		destory_node(int fd, t_dict **dict);
char		*out_value(int fd, t_dict *dict);
void		self_check(t_dict **dict);

char		*read_fd(int fd, char *save_buf);
char		*out_put(int fd, char *read_buf, t_dict **dict);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strbox(int i, const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif