#include "philo.h"

int	start_game(t_philo *philo)
{
	int	i;
	pid_t	pid;

	i = 0;
	philo->inform->block = 1;

	while(i < philo->inform->number_of_philosophers)
	{
		if (i % 2 == 1)
			pthread_create(&pid, NULL, odd_case, (void *)&philo[i]);
		else
			pthread_create(&pid, NULL, even_case, (void *)&philo[i]);
	}
	philo->inform->block = 0;
	
}

void	*odd_case(void *atr)
{
	t_philo *arr = (t_philo *)atr;
	while (arr->inform->block);
	printf("%d\n", 1);
	return (NULL);
}

void	*even_case(void *atr)
{
	t_philo *arr = (t_philo *)atr;
	while (arr->inform->block);
	printf("%d\n", 1);
	return (NULL);
}