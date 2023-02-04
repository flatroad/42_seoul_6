/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:09:18 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/28 16:39:45 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (ptr == 0)
		return (0);
	ptr = ft_memmove(ptr, s1, s1_len);
	ptr = ft_memmove((ptr + s1_len), s2, s2_len);
	ptr = (ptr - s1_len);
	ptr[s1_len + s2_len] = 0;
	return (ptr);
}
