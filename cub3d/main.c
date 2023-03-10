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

void	argc_error_handle(int cas)
{
	if (cas == 0)
		write(2, "Error, No map file..\n", 22);
	if (cas == 1)
		write(2, "Error, a lot of files..\n", 25);
}

int	file_validity(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd <= 0)
		printf("%s\n", strerror(errno));
	return (*fd);
}

int	cub3d(char *file, int fd)
{
	if (file_validity(file, &fd) <= 0)
		return (1);
	if (map_validity(fd) == 1)
		return (1);

}

// int	map_validity(int fd)
// {
// 	char	*str;
// 	char	

// 	str = get_next_line(fd);
// 	while (str != NULL)
// 	{
		
// 	}
// }


int	map_validity(char **arr)
{
	int	checker[2];

	checker[0] = 0;
	checker[1] = 0;
	find_start_point(arr, checker);
	if (outline_check(arr, checker) == 1)
		return (1);
}