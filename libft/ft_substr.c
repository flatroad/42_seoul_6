/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:44:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/31 12:39:06 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	size_t	s_len;
	char	*ptr;

	if (s == 0 || len == 0)
		return (0);
	idx = 0;
	s_len = ft_strlen(s);
	if (s_len < start)
		return (0);
	if (s_len - start < len)
		len = s_len - start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == 0)
		return (0);
	ptr = ft_memmove(ptr, &(s[start]), len);
	ptr[len] = 0;
	return (ptr);
}
