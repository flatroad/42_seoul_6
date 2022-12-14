/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moniter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:11:01 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 08:11:01 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*moniter(void *atr)
{
	t_philo	philo;

	philo = *(t_philo *)atr;
	while (1)
	{
		sem_wait(philo.time);
		if (get_time() - *philo.r_time > philo.inform->time_to_die)
		{
			sem_print(philo, "is dead", 1);
			break ;
		}
		sem_post(philo.time);
		usleep(100);
	}
	exit(0);
}
