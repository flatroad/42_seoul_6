/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:43 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/11 23:54:08 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (1)
	{
		write(1, "c> ", 2);
		check = mk_doc(flag_str, start_fd, len);
		if (check == 1)
			return (1);
		if (check == 0)
			break ;
	}
	close(start_fd);
	pipex->infile_fd = open("./temp", O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		perror("error_check3 ");
		return (1);
	}
	return (0);
}

int	mk_doc(char *flag_str, int start_fd, int len)
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
	write(start_fd, line, len_line);
	free(line);
	line = 0;
	return (2);
}
