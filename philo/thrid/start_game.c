#include "philo.h"

int	start_game(t_philo *philo)
{
	int	i;
	pthread_t	pid;

	i = 0;
	*philo->inform->block = 1;
	while(i < philo->inform->number_of_philosophers)
	{
		if (i % 2 == 1)
			pthread_create(&pid, NULL, odd_case, (void *)&philo[i]);
		else
			pthread_create(&pid, NULL, even_case, (void *)&philo[i]);
		i++;
	}
	gettimeofday(&philo->inform->s_time, NULL);
	*philo->inform->block = 0;
	sleep(10);
	return (0);
}


void	*odd_case(void *atr)
{
	struct timeval	s_t;
	struct timeval	c_t;
	t_philo *arr = (t_philo *)atr;
	while (*arr->inform->block);
	usleep(10);
	pickup_first(arr, s_t);
	eating_first(arr, s_t);
	while (1)
	{
		downturn(arr);
		sleeping(arr);
		thinking(arr);
		pickup(arr);
		eating(arr);
	}
	return (NULL);
}

void	pickup_first(t_philo *arr, struct timeval s_t)
{
	while (s_t.)
}

void	*even_case(void *atr)
{
	struct timeval	s_t;
	t_philo *arr = (t_philo *)atr;
	while (*arr->inform->block);
	pickup_first(arr);
	eating_first(arr);
	while (1)
	{
		downturn(arr);
		sleeping(arr);
		thinking(arr);
		pickup(arr);
		eating(arr);
	}
	return (NULL);
}

void	pickup(t_philo *arr)
{
	while (1)
	{
		check_time
	}
}


void	check_time(struct timeval s_t)
{
	gettimeofday(s_t
}

 diffTime = ( endTime.tv_sec - startTime.tv_sec ) + (( endTime.tv_usec - startTime.tv_usec ) / 1000000);