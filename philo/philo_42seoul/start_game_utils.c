/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:14:59 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/13 19:57:14 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	s_t;
	long long		time;

	gettimeofday(&s_t, NULL);
	time = s_t.tv_sec * 1000 + s_t.tv_usec / 1000;
	return (time);
}

int	mutex_print(t_philo *arr, char *s, long long c_t)
{
	pthread_mutex_lock(&arr->inform->print_mx);
	if (!((arr->inform->block)))
		printf("%lld [%3d] %s\n", c_t - arr->inform->s_time, arr->idx, s);
	else
	{
		pthread_mutex_unlock(&arr->inform->print_mx);
		return (1);
	}
	pthread_mutex_unlock(&arr->inform->print_mx);
	return (0);
}

int	check_time(t_philo *arr, long long s_t)
{
	long long	c_t;

	c_t = get_time();
	if ((c_t) - (s_t) > arr->inform->time_to_die)
	{
		pthread_mutex_lock(&arr->inform->print_mx);
		if (!(arr->inform->block))
		{
			(arr->inform->block) = arr->idx;
			printf("%lld [%3d] died\n", c_t - arr->inform->s_time, arr->idx);
		}
		pthread_mutex_unlock(&arr->inform->print_mx);
		return (1);
	}
	return (0);
}
