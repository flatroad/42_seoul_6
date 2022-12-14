#include "philo_bonus.h"

int	live_or_die(t_philo philo)
{
	philo.r_time = philo.inform->s_time;
	start_moniter(philo);
	pick_up(philo);
	while (1)
	{
		kill(philo.id, SIGINT);
		eating(philo);
		sleeping(philo);
		pick_up(philo);
	}
	return (0);
}

void	start_moniter(t_philo philo)
{

	philo.r_time = get_time();
	philo.id = fork();
	if (philo.id == -1)
		exit(0);
	else if (philo.id == 0)
	{
		if(moniter(philo) == 1)
			sem_print(philo, "is dead", 1);
		exit(0);
	}
}

int	moniter(t_philo philo)
{
	while(1)
	{
		if(get_time() - philo.r_time > philo.inform->time_to_die)
			return (1);
		usleep(100);
	}
	return (0);
}

void	pick_up(t_philo philo)
{
	sem_wait(philo.inform->fork);
	sem_wait(philo.inform->fork);
	sem_print(philo, "has fork", 0);
}

int	eating(t_philo philo)
{
	start_moniter(philo);
	sem_print(philo, "is eating", 0);
	if (++philo.count == philo.inform->number_of_times_each_philosopher_must_eat)
	{
		sem_post(philo.inform->fork);
		sem_post(philo.inform->fork);
		return (1);
	}
	while (get_time() - philo.r_time < philo.inform->time_to_eat)
		usleep(400);
	sem_post(philo.inform->fork);
	sem_post(philo.inform->fork);
	return (0);
}

void	sleeping(t_philo philo)
{
	long long	x;

	x = get_time();
	sem_print(philo, "is sleep", 0);
	while (get_time() - x < philo.inform->time_to_sleep)
		usleep(400);
	sem_print(philo, "is thinking", 0);
}
