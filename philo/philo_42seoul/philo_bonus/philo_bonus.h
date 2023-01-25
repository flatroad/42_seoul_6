/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 08:13:56 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_inform
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	sem_t			*fork;
	sem_t			*sem_pr;
	sem_t			*dead;
	sem_t			*pull;
	long long		s_time;
	long long		put_t;
}	t_inform;

typedef struct s_philo
{
	pthread_t		id;
	pid_t			pid;
	int				idx;
	int				count;
	long long		*r_time;
	t_inform		*inform;
	sem_t			*time;
}	t_philo;

int			philo_bonus(int argc, char **argv);

int			error_handle(int i);
void		error_write(char *str);

int			check_factor(int argc, char **argv, t_inform *inform);
int			is_num(int argc, char **argv);
int			is_int(int argc, char **argv, t_inform *inform);

size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);

int			init_data(t_philo *philo, t_inform *inform, int num);
int			init_philo(t_philo *philo, int num, t_inform *inform);
int			init_sem(t_inform *inform, int num);

int			start_game(t_philo *philo, t_inform *inform, int num);
void		wait_pid(t_inform *inform, int num);
void		*is_dead(void *atr);
int			start_fork(t_philo *philo, t_inform *inform, int num);

long long	get_time(void);
void		sem_print(t_philo philo, char *s, int i);

int			live_or_die(t_philo philo);
void		pick_up(t_philo philo);
int			eating(t_philo philo);
void		sleeping(t_philo philo);

void		free_all(t_philo *philo);

void		*moniter(void *atr);

#endif