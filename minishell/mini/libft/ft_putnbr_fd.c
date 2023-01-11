/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 21:19:45 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/30 21:19:46 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_change(int n, char *str, int count, int judge)
{	
	int	part;

	part = 0;
	while (count-- != 0)
	{
		part = n % 10;
		n = n / 10;
		str[count] = judge * part + 48;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		judge;
	char	str[11];
	int		count;

	judge = 1;
	count = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	if (n < 0)
	{
		judge = -1;
		write(fd, "-", 1);
	}
	count = ft_count(n);
	ft_change(n, str, count, judge);
	str[count] = 0;
	write(fd, str, count);
}
