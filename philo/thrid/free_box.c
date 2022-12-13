/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:52:31 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/13 10:55:35 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_mutex(pthread_mutex_t *fork_mx, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_destroy(&fork_mx[i]);
		i++;
	}
}

void	free_pthread(t_philo *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_detach(philo->id);
		i++;
	}
}

void	free_all(t_philo *philo, t_part *part, t_inform *inform)
{
	free_mutex(part->fork_mx, inform->number_of_philosophers);
	pthread_mutex_destroy(&inform->print_mx);
	free(part->fork_mx);
	free(part->bool_fork);
	part->bool_fork = 0;
	free(philo);
	philo = 0;
}
