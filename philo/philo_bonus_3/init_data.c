#include "philo_bonus.h"

int	init_data(t_philo *philo, t_inform *inform, int num)
{
	int	err;

	err = 0;
	sem_unlink("sem_dead");
	sem_unlink("sem_fork");
	sem_unlink("sem_pull");
	sem_unlink("sem_print");
	sem_unlink("sem_time");
	err = init_sem(inform, num);
	if (err == 1)
		return (6);
	if (init_philo(philo, num, inform) == 1)
		return (7);
	return (0);
}

int	init_philo(t_philo *philo, int num, t_inform *inform)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philo[i].count = 0;
		philo[i].idx = (i + 1);
		philo[i].inform = inform;
		i++;
	}
	return (0);
}

int	init_sem(t_inform *inform, int num)
{
	inform->dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	if (inform->dead == SEM_FAILED)
		return (1);
	inform->fork = sem_open("sem_fork", O_CREAT | O_EXCL, 0644, num);
	if (inform->fork == SEM_FAILED)
	{
		sem_close(inform->dead);
		return (1);
	}
	inform->pull = sem_open("sem_pull", O_CREAT | O_EXCL, 0644, num);
	if (inform->pull == SEM_FAILED)
	{
		sem_close(inform->dead);
		sem_close(inform->fork);
		return (1);
	}
	inform->sem_pr = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	if (inform->sem_pr == SEM_FAILED)
	{
		sem_close(inform->dead);
		sem_close(inform->fork);
		sem_close(inform->pull);
		return (1);
	}
	return (0);
}