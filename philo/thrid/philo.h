/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/09 19:23:58 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct s_inform
{
	int				*block;
	int				mode;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				check_print;
	pthread_mutex_t	print_mx;
	pthread_mutex_t	time;
	struct timeval	s_time;
}	t_inform;

typedef struct s_philo
{
	pthread_t id;
	int				idx;
	int				count;
	int				*fork_r;
	int				*fork_l;
	pthread_mutex_t	*fork_mx_r;
	pthread_mutex_t	*fork_mx_l;
	t_inform		*inform;
}	t_philo;

typedef struct s_part
{
	pthread_mutex_t	*fork_mx;
	int				*bool_fork;
}	t_part;

// check_factor_utils
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

// check_factor
int		check_factor(int argc, char **argv, t_inform *inform);
int		is_num(int argc, char **argv);
int		is_int(int argc, char **argv, t_inform *inform);

// error_handle
int		error_handle(int i);
void	error_write(char *str);

// philo
int		philo(int argc, char **argv);
int		check_init(t_inform *inform, t_part *part, t_philo *philo, int num);
//init_philo
int		init_part(t_inform *inform, t_part *part, int num);
int		pull_bool_fork(int num, t_part *part);
int		pull_mutex(int num, t_part *part);
int		init_mutex(t_inform *inform);
int		init_philo(t_philo *philo, t_inform *inform, t_part *part, int num);

//free_mutex
void	free_mutex(pthread_mutex_t *fork_mx, int num);

//start_game
int		start_game(t_philo *philo);
void	*odd_case(void *atr);
void	*even_case(void *atr);

#endif
