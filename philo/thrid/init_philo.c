/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:31:08 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 17:31:33 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_part(t_inform *inform, t_part *part, int num)
{
	if (pull_bool_fork(num, part->bool_fork) == 1)
		return (4);
	if (pull_mutex(num, part->fork_mx) == 1)
	{
		free(part->bool_fork);
		part->bool_fork = 0;
		return (5);
	}
	return (0);
}

int	pull_bool_fork(int num, int *bool_fork)
{
	int	i;

	i = 0;
	bool_fork = (int *)malloc(sizeof(int) * num);
	if (bool_fork == NULL)
		return (1);
	while (i < num)
	{
		bool_fork[i] = 1;
		i++;
	}
	return (0);
}

int	pull_mutex(int num, pthread_mutex_t *fork_mx)
{
	int	i;

	i = 0;
	fork_mx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (fork_mx == NULL)
		return (1);
	while (i < num)
	{
		if (pthread_mutex_init(&fork_mx[i], NULL) != 0)
		{
			free_mutex(fork_mx, i);
			free(fork_mx);
			fork_mx = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

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
