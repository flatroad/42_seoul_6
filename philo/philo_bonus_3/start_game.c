#include "philo_bonus.h"

int start_game(t_philo *philo, t_inform *inform, int num)
{
	int i;
	pthread_t	dead;

	i = 0;
	sem_wait(inform->dead);
	while (i < num)
	{
		sem_wait(inform->pull);
		i++;
	}
	pthread_create(&dead, NULL, is_dead, inform);
	start_fork(philo, inform, num);
	i = 0;
	while (i < num)
	{
		sem_wait(inform->pull);
		i++;
	}
	printf("%d\n", 123);
	exit(0);
}

void	*is_dead(void *atr)
{
	t_inform	*inform;

	inform = (t_inform *)atr;
	sem_wait(inform->dead);
	kill(0, SIGINT);
	printf("%d\n", 123);
	exit(0);
}

int	start_fork(t_philo *philo, t_inform *inform, int num)
{
	int	i;

	i = 0;
	inform->s_time = get_time();
	while (i < num)
	{
		philo[i].pid = fork();
		if (philo[i].pid == -1)
			return (1);
		else if (philo[i].pid == 0)
		{
			if(live_or_die(philo[i]) == 0)
				sem_post(inform->pull);
		}
		else
			i++;
	}
	return (0);
}
