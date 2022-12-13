/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:08 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/13 17:10:43 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_part(t_inform *inform, t_part *part, int num)
{
	if (pull_bool_fork(num, part) == 1)
		return (4);
	if (init_mutex(inform) == 1)
	{
		free(part->bool_fork);
		part->bool_fork = 0;
		return (5);
	}
	if (pull_mutex(num, part) == 1)
	{
		pthread_mutex_destroy(&inform->print_mx);
		free(part->fork_mx);
		free(part->bool_fork);
		part->bool_fork = 0;
		return (6);
	}
	return (0);
}

int	pull_bool_fork(int num, t_part *part)
{
	int	i;

	i = 0;
	part->bool_fork = (int *)malloc(sizeof(int) * num);
	if (part->bool_fork == NULL)
		return (1);
	while (i < num)
	{
		if (i % 2 == 0)
			part->bool_fork[i] = 0;
		else
			part->bool_fork[i] = i + 1;
		if (i == num - 1)
			part->bool_fork[i] = num;
		i++;
	}
	return (0);
}

int	pull_mutex(int num, t_part *part)
{
	int	i;

	i = 0;
	part->fork_mx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (part->fork_mx == NULL)
		return (1);
	while (i < num)
	{
		if (pthread_mutex_init(&part->fork_mx[i], NULL) != 0)
		{
			free_mutex(part->fork_mx, i);
			free(part->fork_mx);
			part->fork_mx = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

int	init_mutex(t_inform *inform)
{
	if (pthread_mutex_init(&inform->print_mx, NULL) != 0)
		return (1);
	return (0);
}

int	init_philo(t_philo *philo, t_inform *inform, t_part *part, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].count = 0;
		philo[i].idx = i + 1;
		philo[i].fork_l = &part->bool_fork[i];
		philo[i].fork_r = &part->bool_fork[(i + 1) % num];
		philo[i].fork_mx_l = &part->fork_mx[i];
		philo[i].fork_mx_r = &part->fork_mx[(i + 1) % num];
		philo[i].inform = inform;
		i++;
	}
	return (0);
}
