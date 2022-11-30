#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

# define FAIL 0
# define SUSSESS 1

typedef struct s_fork
{
	int				check;
	pthread_mutex_t	*mutex;
	struct s_fork	*next;
}	t_fork;

typedef struct s_inform
{
	int	number_of_philosophers;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_inform;

typedef struct s_philo
{
	int			index;
	t_fork		*fork;
	t_inform	*report;
}	t_philo;

typedef	struct s_error_message
{
	char	*error1;
	int		erint1;
	char	*error2;
	int		erint2;
	char	*error3;
	int		erint3;
}	t_error;


// philo
int	philo(int argc, char **argv);

// init_box
void	init_error(t_error *err);

// error_handle
int		error_handle(int i, t_error err);
void	write_handle(char *str, int len);

// check_param
int	check_param(int argc, char **argv);
int	check_str(char *str, t_error err);
int	ft_strlen(char *str);
int	ft_isdigit(int c);

#endif
