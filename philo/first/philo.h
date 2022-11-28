#ifndef PHILO_H
# define PHILO_H

typedef struct s_philo
{
	int			index;
	int			mutex;
	int			fork;
	t_inform	*report;
}	t_philo;

typedef struct s_message
{

}	t_message;

typedef struct s_inform
{
	int	number_of_philosophers;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_inform;

#endif