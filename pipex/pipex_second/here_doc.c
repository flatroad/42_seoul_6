#include "pipex.h"

int	fd_doc(char *flag_str, t_obj *pipex, int start_fd)
{
	int	len;
	int	check;

	len = ft_strlen(flag_str);
	start_fd = open("./temp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (start_fd == -1)
	{
		perror("error_check3 ");
		return (1);
	}
	pipex->infile_fd = start_fd;
	while (1)
	{
		write(1, "> ", 2);
		check = mk_doc(flag_str, pipex, len);
		if (check == 1)
			return (1);
		if (check == 0)
			break ;
	}
	return (0);
}

int	mk_doc(char *flag_str, t_obj *pipex, int len)
{
	char	*line;
	int		len_line;

	line = get_next_line(0, len + 1);
	if (line == NULL)
		return (1);
	len_line = ft_strlen(line);
	if (strncmp(flag_str, line, len) == 0)
	{
		if (line[len] == '\n')
		{
			free(line);
			line = NULL;
			return (0);
		}
	}
	write(pipex->infile_fd, line, len_line);
	free(line);
	line = 0;
	return (2);
}
