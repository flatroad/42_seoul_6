/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:11:09 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 09:21:00 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	live_or_die(t_philo philo)
{
	philo.r_time = &philo.inform->put_t;
	pthread_create(&philo.id, NULL, moniter, &philo);
	while (1)
	{
		pick_up(philo);
		if (eating(philo) == 1)
			return (0);
		++philo.count;
		sleeping(philo);
	}
	return (0);
}

void	pick_up(t_philo philo)
{
	sem_wait(philo.inform->fork);
	sem_wait(philo.inform->fork);
	sem_print(philo, "has fork", 0);
}

int	eating(t_philo philo)
{
	sem_wait(philo.time);
	*philo.r_time = get_time();
	sem_post(philo.time);
	sem_print(philo, "is eating", 0);
	if (++(philo.count) == \
	philo.inform->number_of_times_each_philosopher_must_eat)
	{
		sem_post(philo.inform->fork);
		sem_post(philo.inform->fork);
		return (1);
	}
	while (get_time() - *philo.r_time < philo.inform->time_to_eat)
		usleep(300);
	sem_post(philo.inform->fork);
	sem_post(philo.inform->fork);
	return (0);
}

void	sleeping(t_philo philo)
{
	long long	x;

	x = get_time();
	sem_print(philo, "is sleep", 0);
	while (get_time() - x < philo.inform->time_to_sleep)
		usleep(300);
	sem_print(philo, "is thinking", 0);
}
