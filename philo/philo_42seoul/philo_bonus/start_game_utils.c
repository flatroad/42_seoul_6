/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:14:59 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/14 19:53:50 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	get_time(void)
{
	struct timeval	s_t;
	long long		time;

	gettimeofday(&s_t, NULL);
	time = s_t.tv_sec * 1000 + s_t.tv_usec / 1000;
	return (time);
}

void	sem_print(t_philo philo, char *s, int i)
{
	sem_wait(philo.inform->sem_pr);
	printf("%lld [%3d] %s\n", get_time() - philo.inform->time, philo.idx, s);
	if (i == 1)
	{
		sem_post(philo.inform->dead);
		return ;
	}
	sem_post(philo.inform->sem_pr);
}
