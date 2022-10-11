#include "pipex.h"
#include <fcntl.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		len;
	int		len_line;

	fd = open("./temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	len = ft_strlen(argv[2]);
	if (fd == -1)
		exit(1);
	while (1)
	{
		write(1, "> ", 2);
		line = get_next_line(0, len + 1);
		len_line = ft_strlen(line);
		if(strncmp(argv[2], line, len) == 0)
		{
			if (line[len] == '\n')
				break;
		}
		write(fd, line, len_line);
		free(line);
		line = 0;
	}
	free(line);
	line = 0;
	return (0);
}
