/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:56 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 17:31:59 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_handle(int i)
{
	if (i == 1)
		error_write("Error\nparam_count_wrong\n");
	if (i == 2)
		error_write("Error\nparam_value_wrong\n");
	if (i == 3)
		error_write("Error\nis_not_int\n");
	if (i == 4)
		error_write("Error\nbool_fork_malloc_fail\n");
	if (i == 5)
		error_write("Error\nfork_mx is wrong\n");
	return (1);
}

void	error_write(char *str)
{
	write(1, str, ft_strlen(str));
}
