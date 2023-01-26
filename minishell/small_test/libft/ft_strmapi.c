/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:21:17 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:21:20 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	idx;
	char	*str;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen((char *)s);
	idx = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	while (idx < len)
	{
		str[idx] = f(idx, s[idx]);
		idx++;
	}
	str[idx] = 0;
	return (str);
}
