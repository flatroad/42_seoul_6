/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:17:19 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:17:20 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	max;

	max = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		max++;
	}
	return (max);
}

static char	*ft_minus(int n, int max, char *n_str)
{
	n_str = (char *)malloc(sizeof(char) * (max + 1));
	if (n_str == 0)
		return (0);
	n_str[max] = 0;
	n_str[0] = '-';
	while (--max)
	{
		n_str[max] = (-(n % 10)) + 48;
		n = n / 10;
	}
	return (n_str);
}

static char	*ft_plus(int n, int max, char *n_str)
{
	n_str = (char *)malloc(sizeof(char) * (max + 1));
	if (n_str == 0)
		return (0);
	n_str[max] = 0;
	while (max--)
	{
		n_str[max] = (n % 10) + 48;
		n = n / 10;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	int		max;
	char	*n_str;

	n_str = 0;
	max = ft_count(n);
	if (n < 0)
		n_str = ft_minus(n, max + 1, n_str);
	else
		n_str = ft_plus(n, max, n_str);
	if (n_str == 0)
		return (0);
	return (n_str);
}
