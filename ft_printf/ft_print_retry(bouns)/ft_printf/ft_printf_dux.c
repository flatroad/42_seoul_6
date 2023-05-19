/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:13:13 by sounchoi          #+#    #+#             */
/*   Updated: 2022/07/06 16:13:14 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_di_printf(int num, int count)
{
	if (num == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		count = ft_di_printf(num / 10, count);
	num = (num % 10) + '0';
	count += write(1, &num, 1);
	return (count);
}

int	ft_u_printf(unsigned int num, int count)
{
	if (num >= 10)
		count = ft_u_printf(num / 10, count);
	num = (num % 10) + '0';
	count += write(1, &num, 1);
	return (count);
}

int	ft_xX_printf(unsigned int num, char c, int count)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	count = ft_hex_printf(num, hex, count);
	return (count);
}
