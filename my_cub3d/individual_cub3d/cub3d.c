#include "cub3d.h"

int	cub3d(char *file, int fd)
{
	if (file_validity(file, &fd) <= 0)
		return (1);
	if (map_validity(fd) == 1)
		return (1);

}