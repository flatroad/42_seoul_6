/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:56 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/13 10:55:29 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handle(int i)
{
	if (i == 1)
		error_write("Error\nparam count wrong\n");
	if (i == 2)
		error_write("Error\nparam value wrong\n");
	if (i == 3)
		error_write("Error\nis not int\n");
	if (i == 4)
		error_write("Error\nbool_fork malloc fail\n");
	if (i == 5)
		error_write("Error\ninform_mutex is wrong\n");
	if (i == 6)
		error_write("Error\nfork_mx is wrong\n");
	if (i == 7)
		error_write("Error\npthread creat fail\n");
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
