/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:08 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/14 16:36:18 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	init_data(t_philo *philo, t_inform *inform, int num)
{
	int	err;

	err = 0;
	init_philo(philo, num);
	err = init_sem(inform, num);
	if (err == 1)
		return (error_handle(4));
	return (0);
}

void	init_philo(t_philo *philo, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].count = 0;
		philo[i].idx = i + 1;
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
		sem_unlink(inform->fork);
		sem_close(inform->fork);
		return (1);
	}
	inform->finish = sem_open("finish", O_CREAT | O_EXCL, 0644, 1);
	if (inform->finish == -1)
	{
		sem_unlink(inform->fork);
		sem_close(inform->fork);
		sem_unlink(inform->sem_pr);
		sem_close(inform->sem_pr);
		return (1);
	}
	return (0);
}
