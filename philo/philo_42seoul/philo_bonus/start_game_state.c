/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:06:11 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/14 19:42:30 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*live_or_die(void *atr)
{
	t_philo		*arr;
	long long	s_t;

	arr = (t_philo *)atr;
	pthread_mutex_lock(&arr->inform->print_mx);
	while (arr->inform->block)
		;
	pthread_mutex_unlock(&arr->inform->print_mx);
	if (arr->idx % 2 == 0)
		usleep(1000);
	pickup(arr, arr->inform->s_time);
	while (1)
	{
		if (!(eating(arr, &s_t) && sleeping(arr, s_t) && pickup(arr, s_t)))
			break ;
	}
	return (NULL);
}

int	pickup(t_philo *arr, long long s_t)
{
	while (1)
	{
		if (pickup_check(arr) == 1)
			return (1);
		if (check_time(arr, s_t))
			break ;
		usleep(300);
	}
	return (0);
}

int	pickup_check(t_philo *arr)
{
	pthread_mutex_lock(arr->fork_mx_l);
	if (*arr->fork_l != arr->idx)
	{
		pthread_mutex_unlock(arr->fork_mx_l);
		pthread_mutex_lock(arr->fork_mx_r);
		if (*arr->fork_r != arr->idx)
		{
			mutex_print(arr, "has taken a fork");
			pthread_mutex_unlock(arr->fork_mx_r);
			return (1);
		}
		else
		{
			pthread_mutex_unlock(arr->fork_mx_r);
			pthread_mutex_lock(arr->fork_mx_l);
		}
	}
	pthread_mutex_unlock(arr->fork_mx_l);
	return (0);
}

int	eating(t_philo *arr, long long *s_t)
{
	*s_t = get_time();
	if (mutex_print(arr, "is eating"))
		return (0);
	if (++arr->count == arr->inform->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(arr->fork_mx_l);
		pthread_mutex_lock(arr->fork_mx_r);
		*(arr->fork_l) = arr->idx;
		*(arr->fork_r) = arr->idx;
		pthread_mutex_unlock(arr->fork_mx_l);
		pthread_mutex_unlock(arr->fork_mx_r);
		return (0);
	}
	while (get_time() - *s_t <= arr->inform->time_to_eat)
		usleep(100);
	pthread_mutex_lock(arr->fork_mx_l);
	pthread_mutex_lock(arr->fork_mx_r);
	*(arr->fork_l) = arr->idx;
	*(arr->fork_r) = arr->idx;
	pthread_mutex_unlock(arr->fork_mx_l);
	pthread_mutex_unlock(arr->fork_mx_r);
	return (1);
}

int	sleeping(t_philo *arr, long long s_t)
{
	long long	c_t;

	c_t = get_time();
	if (mutex_print(arr, "is sleeping"))
		return (0);
	while (get_time() - c_t <= arr->inform->time_to_sleep)
	{
		if (check_time(arr, s_t))
			return (0);
		usleep(300);
	}
	if (mutex_print(arr, "is thinking"))
		return (0);
	usleep(400);
	return (1);
}
