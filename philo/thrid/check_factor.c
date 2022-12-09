/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_factor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:51:20 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/09 18:34:53 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_factor(int argc, char **argv, t_inform *inform)
{
	if (argc < 5 || argc > 6)
		return (1);
	if (is_num(argc, argv) != 0)
		return (2);
	if (is_int(argc, argv, inform) != 0)
		return (3);
	return (0);
}

int	is_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = (int)ft_strlen(argv[i]);
		while ((9 <= argv[i][j] && argv[i][j] <= 14) || argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+')
			j++;
		while (j < len && ft_isdigit(argv[i][j]) == 1)
			j++;
		while ((9 <= argv[i][j] && argv[i][j] <= 14) || argv[i][j] == ' ')
			j++;
		if (len == 0 || j != len)
			return (2);
		i++;
	}
	return (0);
}

int	is_int(int argc, char **argv, t_inform *inform)
{
	inform->mode = argc;
	inform->number_of_philosophers = ft_atoi(argv[1]);
	inform->time_to_die = ft_atoi(argv[2]);
	inform->time_to_eat = ft_atoi(argv[3]);
	inform->time_to_sleep = ft_atoi(argv[4]);
	inform->number_of_times_each_philosopher_must_eat = -2;
	if (inform->mode == 6)
		inform->number_of_times_each_philosopher_must_eat = \
		ft_atoi(argv[5]);
	if (inform->number_of_philosophers == -1 || \
	inform->number_of_times_each_philosopher_must_eat == -1 || \
	inform->time_to_die == -1 || inform->time_to_eat == -1 || \
	inform->time_to_sleep == -1)
		return (3);
	return (0);
}
