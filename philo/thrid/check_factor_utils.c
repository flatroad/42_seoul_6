/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_factor_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:12 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 07:53:12 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	num;

	num = 0;
	while ((9 <= *str && *str <= 14) || *str == ' ')
		str++;
	if ('+' == *str)
		str++;
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (*str - 48);
		if (num > 2147483647)
			return (-1);
		str++;
	}
	return (num);
}
