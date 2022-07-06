/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:21:35 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:21:37 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	idx_t;

	idx = 0;
	idx_t = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[idx] != 0 && idx < len)
	{
		idx_t = 0;
		while ((haystack[idx + idx_t] == needle[idx_t]) && \
		needle[idx_t] != 0)
			idx_t++;
		if (needle[idx_t] == 0 && (idx + idx_t) <= len)
			return ((char *)&haystack[idx]);
		idx++;
	}
	return (0);
}
