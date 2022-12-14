/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:08 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/14 19:20:24 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(t_philo *philo, t_inform *inform, int num)
{
	int	err;

	err = 0;
	init_philo(philo, inform, num);
	err = init_sem(inform, num);
	if (err == 1)
		return (error_handle(4));
	return (0);
}

void	init_philo(t_philo *philo, t_inform *inform, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].count = 0;
		philo[i].idx = i + 1;
		philo[i].inform = inform;
		i++;
	}
}

int	init_sem(t_inform *inform, int num)
{
	inform->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, num);
	if (inform->fork == -1)
		return (1);
	inform->sem_pr = sem_open("print", O_CREAT | O_EXCL, 0644, 1);
	if (inform->sem_pr == -1)
	{
		free_sem(inform->fork);
		return (1);
	}
	inform->dead = sem_open("finish", O_CREAT | O_EXCL, 0644, 1);
	if (inform->dead == -1)
	{
		free_sem(inform->fork);
		free_sem(inform->sem_pr);
		return (1);
	}
	inform->pull = sem_open("pull", O_CREAT | O_EXCL, 0644, num);
	if (inform->pull == -1)
	{
		free_sem(inform->fork);
		free_sem(inform->sem_pr);
		free_sem(inform->dead);
		return (1);
	}
	return (0);
}
