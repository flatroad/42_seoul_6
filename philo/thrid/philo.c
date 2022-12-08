/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:52 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 17:32:02 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char **argv)
{
	int			err;
	t_inform	inform;
	t_philo		*philo;
	t_part		part;

	err = check_factor(argc, argv, &inform);
	if (err != 0)
		return (error_handle(err));
	write(1, "sussess\n", 9);
	err = init_part(&inform, &part, inform.number_of_philosophers);
	if (err != 0)
		return (error_handle(err));
	return (0);
}
