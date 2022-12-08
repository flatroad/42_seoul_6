/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:52 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 20:06:52 by sounchoi         ###   ########.fr       */
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
	philo = (t_philo *)malloc(sizeof(t_philo) * inform.number_of_philosophers);
	if (philo == NULL)
		return (error_handle(6));
	err = check_init(&inform, &part, philo, inform.number_of_philosophers);
	if (err != 0)
		return (error_handle(err));
	err = start_game(philo);
	if (err != 0)
		return (error_handle(err));
	return (0);
}

int	check_init(t_inform *inform, t_part *part, t_philo *philo, int num)
{
	int	err;

	err = 0;
	err = init_part(inform, part, num);
	if (err != 0)
		return (err);
	err = init_philo(philo, inform, part, num);
	if (err != 0)
	{
		free_mutex(part->fork_mx, num);
		pthread_mutex_destroy(&inform->print_mx);
		pthread_mutex_destroy(&inform->time);
		free(&part->bool_fork);
		part->bool_fork = 0;
		return (err);
	}
	return (0);
}
