/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:55:46 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:19:21 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_st;
	unsigned char	c_tr;
	size_t			count;

	b_st = (unsigned char *)b;
	c_tr = (unsigned char)c;
	count = 0;
	while (count < len)
	{
		b_st[count] = c_tr;
		count++;
	}
	return (b);
}
