/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/14 16:30:50 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <semaphore.h>

typedef struct s_inform
{
	int				mode;
	//필로소퍼 수
	int				number_of_philosophers;
	// 죽음까지의 시간.
	int				time_to_die;
	// 밥 먹는 시간.
	int				time_to_eat;
	// 잠 자는 시간.
	int				time_to_sleep;
	// 먹는 횟수.
	int				number_of_times_each_philosopher_must_eat;
	// 세마포어 포크
	sem_t			*fork;
	// 세마포어 print
	sem_t			*sem_pr;
	// 마지막을 막는 세마포어.
	sem_t			*finish;
}	t_inform;

typedef struct s_philo
{
	// 모니터링 쓰레드.
	pthread_t		id;
	// fork
	pid_t			pid;
	// 필로소퍼 번호.
	int				idx;
	// 밥 먹은 횟수.
	int				count;
}	t_philo;

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

//init_data
int			init_data(t_philo *philo, t_inform *inform, int num);
void		init_philo(t_philo *philo, int num);
int			init_sem(t_inform *inform, int num);


#endif
