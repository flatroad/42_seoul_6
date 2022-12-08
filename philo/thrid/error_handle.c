#include "philo.h"

int	error_handle(int i)
{
	if (i == 1)
		error_write("Error\nparam_count_wrong\n");
	if (i == 2)
		error_write("Error\nparam_value_wrong\n");
	if (i == 3)
		error_write("Error\nis_not_int\n");
	return (1);
}

void	error_write(char *str)
{
	write(1, str, ft_strlen(str));
}