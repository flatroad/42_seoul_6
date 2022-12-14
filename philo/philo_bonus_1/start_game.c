#include "philo_bonus.h"

int start_game(t_philo *philo, t_inform *inform, int num)
{
	start_dead_check(inform->finish);
}

void	start_dead_check(sem_t *finish)
{
	pthread_t *fin;
	pthread_create(fin, 0, when_you_dead, (void *)finish);
}

void	when_you_dead(void *param)
{
	sem_t *finish;

	finish = (sem_t *)param;
	sem_wait(finish);
	while (1)
	{
		usleep(1000 * 1000);
	}
}