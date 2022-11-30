#include "philo.h"

int	philo(int argc, char **argv)
{
	if (check_param(argc, argv) == FAIL)
		return (FAIL);
	if (trans_param(argc, argv) == FAIL)
		return (FAIL);
	return (SUSSESS);
}
