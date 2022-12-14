/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:10:45 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 08:10:58 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philo)
{
	int	i;

	i = 0;
	sem_close(philo->inform->dead);
	sem_close(philo->inform->fork);
	sem_close(philo->inform->pull);
	sem_close(philo->inform->sem_pr);
	while (i < philo->inform->number_of_philosophers)
	{
		sem_close(philo[i].time);
		i++;
	}
}
