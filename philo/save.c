#include "philo.h"

int	init_philo(t_inform *inform, t_philo *philo, int num)
{
	int *bool_fork;
	pthread_mutex_t *fork_mx;

	if (pull_bool_fork(num, bool_fork) == 1)
		return (4);
	if (pull_fork_mx(num, fork_mx, inform) == 1)
	{
		
		return (error_handle(5));
	}
	if (pull_philo(num, philo, bool_fork, fork_mx) == 1)
		return (error_handle(6));
}

int	pull_bool_fork (int num, int *bool_fork)
{
	int	i;

	i = 0;
	bool_fork = (int *)malloc(sizeof(int) * num);
	if (bool_fork == NULL)
		return (1);
	while (i < num)
	{
		bool_fork[i] = 1;
		i++;
	}
	return (0);
}

int pull_fork_mx(int num, pthread_mutex_t *fork_mx, t_inform *inform)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&inform->print_mx, NULL) != 0
	fork_mx = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (fork_mx == NULL)
		return (1);
	while (i < num)
	{
		if (pthread_mutex_init(&fork_mx[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	pull_philo(int num, t_philo *philo, int *bool_box, pthread_mutex_t *fork_mx)
{
	int	i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * num);
	if (philo == NULL)
		return (1);
	while (i < num)
	{
		
	}
	
}

int	push_philo(t_philo *philo, int *bool_box, pthread_mutex_t *fork_mx, int i)
{
	philo->idx = i;
	philo->count = 0;
	philo->fork_l = &bool_box[i];
	philo->fork_r = &bool_box[(i + 1) % ]
}


