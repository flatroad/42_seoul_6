/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:12:36 by sounchoi          #+#    #+#             */
/*   Updated: 2022/07/06 16:12:50 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		count;

	va_start(list, str);
	count = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			str++;
			count = ft_arg (list, *str, count);
		}
		else
			count += write (1, str, 1);
		str++;
	}
	va_end(list);
	return (count);
}

int	ft_arg(va_list list, char c, int count)
{
	if (c == 'c')
		count = ft_c_printf (va_arg(list, int), count);
	else if (c == 's')
		count = ft_s_printf (va_arg(list, char *), count);
	else if (c == 'p')
		count = ft_p_printf (va_arg(list, void *), count);
	else if (c == 'd' || c == 'i')
		count = ft_di_printf (va_arg(list, int), count);
	else if (c == 'u')
		count = ft_u_printf (va_arg(list, unsigned int), count);
	else if (c == 'x' || c == 'X')
		count = ft_xX_printf (va_arg(list, unsigned int), c, count);
	else if (c == '%')
		count += write (1, "%", 1);
	return (count);
}

int	ft_hex_printf(unsigned long num, char *hex, int count)
{
	if (num >= 16)
		count = ft_hex_printf(num / 16, hex, count);
	num = num % 16;
	count += write(1, &(hex[num]), 1);
	return (count);
}
