/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:12:57 by sounchoi          #+#    #+#             */
/*   Updated: 2022/07/06 16:13:10 by sounchoi         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

int	ft_printf (const char *str, ...);
int	ft_arg (va_list list, char c, int count);

int	ft_c_printf (int num, int count);
int	ft_s_printf(char *str, int count);
int ft_p_printf (void *str, int count);
int	ft_di_printf(int num, int count);
int	ft_u_printf(unsigned int num, int count);
int	ft_xX_printf(unsigned int num, char c, int count);

int	ft_hex_printf(unsigned long num, char *hex, int count);


#endif
