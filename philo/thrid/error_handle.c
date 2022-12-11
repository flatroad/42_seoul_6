/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choinagi <choinagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:56 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/11 17:12:33 by choinagi         ###   ########.fr       */
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
		error_write("Error\nfork_mx is wrong");
	if (i == 7)
		error_write("Error\npthread creat fail");
	return (1);
}

void	error_write(char *str)
{
	write(1, str, ft_strlen(str));
}
