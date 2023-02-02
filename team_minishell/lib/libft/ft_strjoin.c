/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:15:07 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/02 19:51:05 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	size_t	i;
	size_t	j;

	if (!s1 || !s1)
		return (NULL);
	ans = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ans)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		ans[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ans[j++] = s2[i++];
	ans[j] = 0;
	return (ans);
}
