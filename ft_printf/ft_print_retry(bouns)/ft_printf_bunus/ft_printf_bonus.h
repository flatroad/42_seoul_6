/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:12:57 by sounchoi          #+#    #+#             */
/*   Updated: 2023/02/04 21:47:37 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "../libft/libft.h"

typedef	struct s_obj
{
	int			type;
	char		*str;
	int			str_len;
	int			zero_count;
	int			point_count;
	int			space_count;
	int			plus_sign;
	int			sort_sign;
	int			sharp_sign;
	char		*tran_str;
	int			all_len;
}	t_obj;

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
