/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:52 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 04:16:00 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	philo_bonus(int argc, char **argv)
{
	int			err;
	t_inform	inform;
	t_philo		*philo;

	err = check_factor(argc, argv, &inform);
	if (err != 0)
		return (error_handle(err));
	philo = (t_philo *)malloc(sizeof(t_philo) * inform.number_of_philosophers);
	if (philo == NULL)
		return (error_handle(6));
	err = init_data(philo,  &inform, inform.number_of_philosophers);
	if (err != 0)
		return (error_handle(err));
	err = start_game(philo, &inform, inform.number_of_philosophers);
	return (0);
}

