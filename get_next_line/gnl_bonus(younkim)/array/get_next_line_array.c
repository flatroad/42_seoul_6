#include "get_next_line_array.h"

static ssize_t read_line(char **lst, int fd)
{
	ssize_t read_value;
	char *buf;
	char *tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return (-1);
	read_value = 1;
	while (read_value != 0)
	{
		tmp = *lst;
		read_value = read(fd, buf, BUFFER_SIZE);
		buf[read_value] = 0;
		if (read_value == -1 || read_value == 0)
			break;
		*lst = ft_strjoin(*lst, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(*lst, '\n'))
			break;
	}
	free(buf);
	return (read_value);
}

static char *ret_line(char *return_line, char *lst)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (lst[i] && lst[i] != '\n')
		i++;
	if (lst[i] == '\n')
		i++;
	return_line = (char *)malloc(i + 1);
	while (j < i)
	{
		return_line[j] = lst[j];
		j++;
	}
	return_line[j] = 0;
	return (return_line);
}

static char *next_line(char **lst)
{
	char *tmp;

	tmp = *lst;
	if (lst == NULL || *lst == NULL)
		return (NULL);
	if (ft_strchr(*lst, '\n'))
		*lst = ft_strdup(ft_strchr(*lst, '\n') + 1);
	else
		*lst = ft_strdup("");
	if (ft_strlen(*lst) == 0)
	{
		free(*lst);
		*lst = NULL;
	}
	free(tmp);
	tmp = NULL;
	return (*lst);
}

char *get_next_line(int fd)
{
	static char *lst[OPEN_MAX] = {0};
	char *return_line;
	ssize_t read_line_value;

	return_line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	read_line_value = read_line(&lst[fd], fd);
	if (read_line_value == -1 || (read_line_value == 0 && lst[fd] == NULL))
		return (NULL);
	return_line = ret_line(return_line, lst[fd]);
	if (return_line == 0)
		return (NULL);
	lst[fd] = next_line(&lst[fd]);
	return (return_line);
}