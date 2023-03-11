#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		argc_error_handle(0);
	if (argc < 3)
		argc_error_handle(1);
	if (cub3d(argv[1], 0) == 0)
		return (0);
	return (1);
}
