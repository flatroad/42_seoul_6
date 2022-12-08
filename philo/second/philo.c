/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:52:52 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 11:02:35 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo(int argc, char **argv)
{
	int			err;
	t_inform	inform;

	err = check_factor(argc, argv, &inform);
	if (err != 0)
		return (error_handle(err));
	write(1, "sussess\n", 9);
	ready_thread(&inform, argc);
	return (0);
}

int	ready_thread(t_inform  *inform, int argc)
{
	inform->fork = (int *)malloc(sizeof(int) * inform->number_of_philosophers);
	if (inform->fork == NULL)
		return (4);
	inform->fork_mx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)\
	 * inform->number_of_philosophers);
	if (inform->fork_mx == NULL)
	{
		free(inform->fork);
		return (4);
	}
	init_inform(inform);
	

}

int	init_inform(t_inform *inform)
{
	int	i;

	i = 0;
	while (i < inform->number_of_philosophers)
	{
		inform->fork[i] = 0;
		if (pthread_mutex_init(&inform->fork_mx[i], NULL))
			return

	}
}