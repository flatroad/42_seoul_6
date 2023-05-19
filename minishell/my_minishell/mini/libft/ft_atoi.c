/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:51:40 by sounchoi          #+#    #+#             */
/*   Updated: 2022/03/27 16:51:43 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while ((9 <= *str && *str <= 14) || *str == ' ')
		str++;
	if ('-' == *str || '+' == *str)
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = (num * 10) + (sign * (*str - 48));
		str++;
	}
	return (num);
}
