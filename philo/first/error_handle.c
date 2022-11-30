#include "philo.h"

int	error_handle(int i, t_error err)
{
	if (i == 1)
		write_handle(err.error1, err.erint1);
	else if (i == 2)
		write_handle(err.error2, err.erint2);
	return (FAIL);
}

void	write_handle(char *str, int len)
{
	write(2, str, len);
}