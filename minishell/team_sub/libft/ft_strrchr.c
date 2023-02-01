/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:21:43 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/25 21:21:55 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (*s != 0)
	{
		if (*s == (char)c)
			count = 1;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	if (count == 0)
		return (0);
	while (*s != (char)c)
		s--;
	return ((char *)s);
}
