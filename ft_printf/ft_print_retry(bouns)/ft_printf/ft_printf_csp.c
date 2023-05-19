/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:13:16 by sounchoi          #+#    #+#             */
/*   Updated: 2022/07/06 16:13:17 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_c_printf(int num, int count)
{
	count += write(1, &num, 1);
	return (count);
}

int	ft_s_printf(char *str, int count)
{
	while (*str != 0)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	ft_p_printf(void *str, int count)
{
	char			*hex;

	hex = "0123456789abcdef";
	count += write(1, "0x", 2);
	if (str == 0)
		count += write(1, "0", 1);
	else
		count = ft_hex_printf((unsigned long)str, hex, count);
	return (count);
}
