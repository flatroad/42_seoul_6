/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:52 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 13:36:13 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char **argv)
{
	int			err;
	t_inform	inform;
	t_philo		*philo;

	err = check_factor(argc, argv, &inform);
	if (err != 0)
		return (error_handle(err));
	write(1, "sussess\n", 9);
	if(init_philo(&inform, argc, philo) == 1)
		return 

	return (0);
}


int	init_philo(t_inform *inform, int argc, t_philo *philo)
{
	int *bool_fork;
	pthread_mutex_t *fork_mx;

	if (pull_bool_fork(inform->number_of_philosophers, bool_fork) == 1)
		error_handle(4);
	if (pull_fork_mx(inform->number_of_philosophers, fork_mx) == 1)
		error_handle(5);
	if (pull_philo(inform, argc, philo))

}

int	pull_bool_fork (int num, int *bool_fork)
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

int pull_fork_mx(int num, pthread_mutex_t *fork_mx)
{
	int	i;

	i = 0;
	fork_mx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (fork_mx == NULL)
		return (1);
	while (i < num)
	{
		if (pthread_mutex_init(&fork_mx[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}
