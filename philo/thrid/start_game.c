#include "philo.h"

static int mutex_print(t_philo *arr, char *s, long long c_t)
{
		pthread_mutex_lock(&arr->inform->print_mx);
		if (!((arr->inform->block)))
			printf("%lld [%3d] %s\n", c_t - arr->inform->s_time, arr->idx, s);
		else
		{
			pthread_mutex_unlock(&arr->inform->print_mx);
			return (1);
		}
		pthread_mutex_unlock(&arr->inform->print_mx);
		return (0);
}

static long long get_time()
{
	struct timeval	s_t;
	long long time;

	gettimeofday(&s_t, NULL);
	time = s_t.tv_sec * 1000 + s_t.tv_usec / 1000;	
	return (time);
}

static int	check_time(t_philo *arr, long long s_t)
{
	long long c_t;
	c_t = get_time();
	if ((c_t) - (s_t) > arr->inform->time_to_die)
	{
		pthread_mutex_lock(&arr->inform->print_mx);
		if (!(arr->inform->block))
		{
			(arr->inform->block) = arr->idx;
			printf("%lld [%3d] died\n", c_t - arr->inform->s_time, arr->idx);
		}
		pthread_mutex_unlock(&arr->inform->print_mx);
		return (1);
	}
	return (0);
}

static int	pickup(t_philo *arr, long long s_t)
{
	while (1)
	{
		pthread_mutex_lock(arr->fork_mx_l);
		if (*arr->fork_l)
		{
			*arr->fork_l = 0;
			pthread_mutex_unlock(arr->fork_mx_l);
			pthread_mutex_lock(arr->fork_mx_r);
			if (*arr->fork_r)
			{
				*arr->fork_r = 0;
				mutex_print(arr, "has taken a fork", get_time());
				pthread_mutex_unlock(arr->fork_mx_r);
				return (1);
			}
			else
			{
				pthread_mutex_unlock(arr->fork_mx_r);
				pthread_mutex_lock(arr->fork_mx_l);
				*arr->fork_l = 1;
			}
		}
		pthread_mutex_unlock(arr->fork_mx_l);
		if (check_time(arr, s_t))
			break ;
		usleep(300);
	}
	return (0);
}
// static int	pickup(t_philo *arr, long long s_t)
// {
// 	while (1)
// 	{
// 		pthread_mutex_lock(arr->fork_mx_l);
// 		if (*arr->fork_l)
// 		{
// 			*arr->fork_l = 0;
// 			pthread_mutex_lock(arr->fork_mx_r);
// 			if (*arr->fork_r)
// 			{
// 				*arr->fork_r = 0;
// 				mutex_print(arr, "has taken a fork", get_time());
// 				pthread_mutex_unlock(arr->fork_mx_r);
// 				pthread_mutex_unlock(arr->fork_mx_l);
// 				return (1);
// 			}
// 			else
// 				*arr->fork_l = 1;
// 			pthread_mutex_unlock(arr->fork_mx_r);
// 		}
// 		pthread_mutex_unlock(arr->fork_mx_l);
// 		if (check_time(arr, s_t))
// 			break ;
// 		usleep(1000);
// 	}
// 	return (0);
// }

static int	eating(t_philo *arr, long long *s_t)
{
	*s_t = get_time();
	if (mutex_print(arr, "is eating", *s_t))
		return (0);
	while (get_time() - *s_t <= arr->inform->time_to_eat)
		usleep(100);
	pthread_mutex_lock(arr->fork_mx_l);
	pthread_mutex_lock(arr->fork_mx_r);
	*(arr->fork_l) = 1;
	*(arr->fork_r) = 1;
	pthread_mutex_unlock(arr->fork_mx_l);
	pthread_mutex_unlock(arr->fork_mx_r);
	return (1);
}
//5 410 200 200
static int	sleeping(t_philo *arr, long long s_t)
{
	long long c_t = get_time();
	if (mutex_print(arr, "is sleeping", c_t))
		return (0);
	while (get_time() - c_t <= arr->inform->time_to_sleep)
	{
		if (check_time(arr, s_t))
			return (0);
		usleep(300);
	}
	if (mutex_print(arr, "is thinking", get_time()))
		return (0);
	return (1);
}

void	*odd_case(void *atr)
{
	long long	s_t;
	//밥먹었을때 갱신되는 시간 (라이프주기)
	t_philo *arr = (t_philo *)atr;
	while (arr->inform->block);
	if (arr->idx % 2 == 0)
		usleep(300);
	pickup(arr, arr->inform->s_time);
	while (1)
	{
		if (!(eating(arr, &s_t) && sleeping(arr, s_t) && pickup(arr, s_t)))
			break ;	
	}
	return (NULL);
}

int	start_game(t_philo *philo)
{
	int	i;

	i = 0;
	(philo->inform->block) = 1;
	while(i < philo->inform->number_of_philosophers)
	{
		if (pthread_create(&philo[i].id, NULL, odd_case, (void *)&philo[i]) != 0)
		{
		}
		i++;
	}
	philo->inform->s_time = get_time();
	philo->inform->block = 0;
	i = 0;
	while (i < philo->inform->number_of_philosophers)
	{
		pthread_join(philo[i].id, NULL);
		i++;
	}
	return (0);
}
