/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/08 16:18:35 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_part
{
	pthread_mutex_t	*fork_mx;
	int				*bool_fork;
}	t_part;

typedef struct s_inform
{
	int	mode;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	print_mx;
	pthread_mutex_t	time;
}	t_inform;

typedef struct s_philo
{
	int	idx;
	int count;
	int	*fork_r;
	int *fork_l;
	pthread_mutex_t	*fork_mx_r;
	pthread_mutex_t	*fork_mx_l;
	t_inform		*inform;
}	t_philo;

// check_factor_utils
size_t	ft_strlen(const char *s);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

// check_factor
int	check_factor(int argc, char **argv, t_inform *inform);
int	is_num(int argc, char **argv);
int	is_int(int argc, char **argv, t_inform *inform);

// error_handle
int		error_handle(int i);
void	error_write(char *str);

// philo
int	philo(int argc, char **argv);

#endif
