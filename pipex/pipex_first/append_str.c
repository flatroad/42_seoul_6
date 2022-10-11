#include "pipex.h"

int	append_str(char *str, int len, int start_fd)
{
	char	*buf;
	int		buf_len;

	buf = (char *)malloc(sizeof(char) * (len + 1));
	while (1)
	{
		if(read(0, buf, len) == -1)
		{
			perror("error_check3 ");
			return (-1);
		}
		buf_len = ft_strlen(buf);
		write(start_fd, buf, buf_len);
		if (buf_len < len)
			write(start_fd, "\n", 1);
		if (strncmp(buf, str, len) == 0)
			break;
		free(buf);
	}
	free(buf);
	buf = 0;
	return (start_fd);
}
