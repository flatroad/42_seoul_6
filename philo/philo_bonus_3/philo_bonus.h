/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 07:53:42 by sounchoi          #+#    #+#             */
/*   Updated: 2022/12/15 06:29:58 by sounchoi         ###   ########.fr       */
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
# include <signal.h>

typedef struct s_inform
{
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
	sem_t			*dead;
	// 먹는 횟수
	sem_t			*pull;
	// 초기 시간
	long long		s_time;
}	t_inform;

typedef struct s_philo
{
	// 모니터링 쓰레드.
	pid_t			id;
	// fork
	pid_t			pid;
	// 필로소퍼 번호.
	int				idx;
	// 밥 먹은 횟수.
	int				count;
	// 시간
	long long		r_time;
	// inform
	t_inform		*inform;
	// 시간 변경
	sem_t			time;
}	t_philo;

int	philo_bonus(int argc, char **argv);

int	error_handle(int i);
void	error_write(char *str);

int	check_factor(int argc, char **argv, t_inform *inform);
int	is_num(int argc, char **argv);
int	is_int(int argc, char **argv, t_inform *inform);

size_t	ft_strlen(const char *s);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

int		init_data(t_philo *philo, t_inform *inform, int num);
int		init_philo(t_philo *philo, int num, t_inform *inform);
int		init_sem(t_inform *inform, int num);

int start_game(t_philo *philo, t_inform *inform, int num);
void	*is_dead(void *atr);
int	start_fork(t_philo *philo, t_inform *inform, int num);

long long	get_time(void);
void	sem_print(t_philo philo, char *s, int i);

int		live_or_die(t_philo philo);
void	pick_up(t_philo philo);
int		eating(t_philo philo);
void	sleeping(t_philo philo);

void	free_fork(t_philo *philo);

void	start_moniter(t_philo philo);
int		moniter(t_philo philo);

#endif
