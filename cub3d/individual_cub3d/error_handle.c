#include "cub3d.h"

void	argc_error_handle(int cas)
{
	if (cas == 0)
		write(2, "Error, No map file..\n", 22);
	if (cas == 1)
		write(2, "Error, a lot of files..\n", 25);
}