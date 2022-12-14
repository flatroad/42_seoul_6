/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:06:22 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 08:17:56 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_game(t_philo *philo, t_inform *inform, int num)
{
	pthread_t	dead;

	sem_wait(inform->dead);
	wait_pid(inform, num);
	pthread_create(&dead, NULL, is_dead, inform);
	if (start_fork(philo, inform, num) == 1)
	{
		free_all(philo);
		free(philo);
		exit(0);
	}
	wait_pid(inform, num);
	free_all(philo);
	free(philo);
	exit(0);
}

void	wait_pid(t_inform *inform, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		sem_wait(inform->pull);
		i++;
	}
}

void	*is_dead(void *atr)
{
	t_inform	*inform;

	inform = (t_inform *)atr;
	sem_wait(inform->dead);
	kill(0, SIGINT);
	exit(0);
}

int	start_fork(t_philo *philo, t_inform *inform, int num)
{
	int	i;

	i = 0;
	inform->s_time = get_time();
	inform->put_t = inform->s_time;
	while (i < num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == -1)
			return (1);
		else if (philo[i].pid == 0)
		{
			if (live_or_die(philo[i]) == 0)
			{
				sem_post(inform->pull);
				exit(0);
			}
		}
		else
			i++;
	}
	return (0);
}
