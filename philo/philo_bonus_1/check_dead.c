#include "philo_bonus.h"

void	check_dead(t_inform *inform, t_philo *philo)
{
	t_dead		dead;
	pthread_t	*pth;

	dead.inform = inform;
	dead.philo = philo;
	pthread_create(pth, NULL, is_dead, (void *)&dead);
}

void	*is_dead(void *param)
{
	t_dead dead;

	dead = *(t_dead *)param;
	sem_wait(dead.inform->dead);
	sem_post(dead.inform->dead);
	free_all(dead.inform, dead.philo);
	exit(1);
}
