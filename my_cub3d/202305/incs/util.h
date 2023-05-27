/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junlee2 <junlee2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:48:17 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/20 17:57:47 by junlee2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>
# include "data.h"

void	err_exit(char *str);
void	*ft_malloc(size_t size);
void	*ft_calloc(size_t count, size_t size);
int		is_set(char *str, char *set);
size_t	ft_strlen(const char *str);
void	ft_strcpy(char *to, char *str);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);

void	test_input(t_data *data);

#endif