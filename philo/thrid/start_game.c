#include "philo.h"

long long get_time()
{
	struct timeval	s_t;
	long long time;

	gettimeofday(&s_t, NULL);
	time = s_t.tv_sec * 1000 + s_t.tv_usec / 1000;	
	return (time);
}

int	start_game(t_philo *philo)
{
	int	i;

	i = 0;
	*philo->inform->block = 1;
	while(i < philo->inform->number_of_philosophers)
	{
			if (pthread_create(&philo[i].id, NULL, odd_case, (void *)&philo[i]) != 0)
			{
			}
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
	if (arr->idx % 2 == 0)
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

//포크잡다가 죽었는지, 잡는지
void	pickup_first(t_philo *arr, struct timeval s_t)
{
	while (1)
	{
		pthread_mutex_lock(arr->fork_mx_l);
		if (*arr->fork_l)
		{
			*arr->fork_l = 0;
			pthread_mutex_lock(arr->fork_mx_r);
			if (*arr->fork_r)
				*arr->fork_r = 0;
			else
				*arr->fork_l = 0;
			pthread_mutex_unlock(arr->fork_mx_r);
			pthread_mutex_unlock(arr->fork_mx_l);
		}
		else
		{
			*arr->fork_l = 1;
			pthread_mutex_unlock(arr->fork_mx_l);
		}
		usleep(10);
		gettimeofday(&s_t, NULL);
		check_time(s_t ,arr->inform);
	}
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


void	check_time(struct timeval s_t, struct timeval philo_t)
{

}

//  diffTime = ( endTime.tv_sec - startTime.tv_sec ) + (( endTime.tv_usec - startTime.tv_usec ) / 1000000);