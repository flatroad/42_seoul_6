/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:13:28 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/11 19:21:12 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_game(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->inform->print_mx);
	philo->inform->block = 1;
	while (i < philo->inform->number_of_philosophers)
	{
		if (pthread_create(&philo[i].id, NULL, \
			live_or_die, (void *)&philo[i]) != 0)
		{
			free_pthread(philo, i);
			return (7);
		}
		i++;
	}
	philo->inform->s_time = get_time();
	philo->inform->block = 0;
	pthread_mutex_unlock(&philo->inform->print_mx);
	i = 0;
	while (i < philo->inform->number_of_philosophers)
	{
		pthread_join(philo[i].id, NULL);
		i++;
	}
	return (0);
}
