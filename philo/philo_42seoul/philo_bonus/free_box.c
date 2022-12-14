#include "philo_bonus.h"

void	free_sem(sem_t x)
{
	sem_unlink(x);
	sem_close(x);
}
