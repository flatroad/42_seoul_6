/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:56 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/14 16:25:10 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	error_handle(int i)
{
	if (i == 1)
		error_write("Error\nparam count wrong\n");
	if (i == 2)
		error_write("Error\nparam value wrong\n");
	if (i == 3)
		error_write("Error\nis not int\n");
	if (i == 4)
		error_write("Error\nsem_t init fail\n");
	if (i == 8)
		error_write("Error\nphilo is a zero\n");
	if (i == 9)
		error_write("Error\nwhat does it mean to eat 0 times?\n");
	return (1);
}

void	error_write(char *str)
{
	write(1, str, ft_strlen(str));
}
