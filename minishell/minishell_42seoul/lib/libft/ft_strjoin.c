/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 02:15:07 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 22:46:36 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	ans = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ans)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		ans[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		ans[j++] = s2[i++];
	ans[j] = 0;
	return (ans);
}
