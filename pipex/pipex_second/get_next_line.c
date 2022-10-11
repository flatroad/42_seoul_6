#include "pipex.h"

char	*get_next_line(int fd, int buf_size)
{
	static char	*save_buf = NULL;
	char		*read_buf;
	char		*out_line;

	if (save_buf == NULL)
		save_buf = ft_calloc(1, 1);
	if (fd < 0 || buf_size <= 0 || save_buf == 0)
		return (NULL);
	if (ft_strchr(save_buf, '\n') == 0)
		read_buf = analyze(fd, save_buf, buf_size);
	else
		read_buf = analyze_sb(save_buf);
	if (read_buf == NULL)
		return (NULL);
	out_line = out_put(read_buf);
	save_buf = save_put(read_buf);
	free(read_buf);
	return (out_line);
}

char	*analyze(int fd, char *save_buf, int buf_size)
{
	int		flag;
	char	*read_ln;
	char	*free_buf;

	flag = 1;
	while (flag > 0 && save_buf != NULL)
	{
		read_ln = (char *)ft_calloc(1, buf_size + 1);
		if (read_ln == NULL)
		{
			free(save_buf);
			save_buf = NULL;
		}
		free_buf = save_buf;
		flag = read(fd, read_ln, buf_size);
		if (flag < 0)
		{
			free(read_ln);
			break ;
		}
		read_ln[flag] = 0;
		if (ft_strchr((const char *)read_ln, '\n') != 0)
			flag = -1;
		save_buf = ft_strjoin(save_buf, read_ln);
		free(read_ln);
		free(free_buf);
	}
	return (save_buf);
}

char	*analyze_sb(char *save_buf)
{
	char	*read_buf;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(save_buf);
	read_buf = (char *)ft_calloc(len + 1, 1);
	if (read_buf == NULL)
		return (read_buf);
	while (i < len)
	{
		read_buf[i] = save_buf[i];
		i++;
	}
	free(save_buf);
	return (read_buf);
}

char	*out_put(char *read_buf)
{
	char	*out_line;
	size_t	len;
	size_t	idx;

	len = 0;
	idx = 0;
	while (read_buf[len] != 0 && read_buf[len] != '\n')
		len++;
	if (read_buf[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	out_line = ft_calloc(len + 1, 1);
	if (out_line == NULL)
		return (out_line);
	while (idx < len)
	{
		out_line[idx] = read_buf[idx];
		idx++;
	}
	return (out_line);
}

char	*save_put(char *read_buf)
{
	char	*save_put;
	size_t	len;
	size_t	idx;

	len = 0;
	idx = 0;
	while (read_buf[len] != 0 && read_buf[len] != '\n')
		len++;
	if (read_buf[len] == '\n')
		len++;
	if (len == 0)
		return (NULL);
	while (read_buf[len + idx] != 0)
		idx++;
	save_put = ft_calloc(idx + 1, 1);
	if (save_put == NULL)
		return (save_put);
	idx = 0;
	while (read_buf[len + idx] != 0)
	{
		save_put[idx] = read_buf[len + idx];
		idx++;
	}
	return (save_put);
}
