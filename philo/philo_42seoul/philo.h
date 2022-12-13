/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/13 22:01:21 by sounchoi         ###   ########.fr       */
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
	int				block;
	int				mode;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				check_print;
	pthread_mutex_t	print_mx;
	long long		s_time;
}	t_inform;

typedef struct s_philo
{
	pthread_t		id;
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

//start_game_cutils
long long	get_time(void);
int			mutex_print(t_philo *arr, char *s_philo);
int			check_time(t_philo *arr, long long s_t);

// check_factor_utils
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

// check_factor
int			check_factor(int argc, char **argv, t_inform *inform);
int			is_num(int argc, char **argv);
int			is_int(int argc, char **argv, t_inform *inform);

// error_handle
int			error_handle(int i);
void		error_write(char *str);

// philo
int			philo(int argc, char **argv);
int			check_init(t_inform *inform, t_part *part, t_philo *philo, int num);
//init_philo
int			init_part(t_inform *inform, t_part *part, int num);
int			pull_bool_fork(int num, t_part *part);
int			pull_mutex(int num, t_part *part);
int			init_mutex(t_inform *inform);
int			init_philo(t_philo *philo, t_inform *inform, t_part *part, int num);

//free_mutex
void		free_mutex(pthread_mutex_t *fork_mx, int num);
void		free_pthread(t_philo *philo, int num);
void		free_all(t_philo *philo, t_part *part, t_inform *inform);

//start_game
int			start_game(t_philo *philo);
void		*live_or_die(void *atr);

//start_game_state
void		*live_or_die(void *atr);
int			pickup(t_philo *arr, long long s_t);
int			pickup_check(t_philo *arr);
int			eating(t_philo *arr, long long *s_t);
int			sleeping(t_philo *arr, long long s_t);

#endif
