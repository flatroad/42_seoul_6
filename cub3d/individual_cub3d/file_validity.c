#include "cub3d.h"

int	file_validity(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd <= 0)
		printf("%s\n", strerror(errno));
	return (*fd);
}