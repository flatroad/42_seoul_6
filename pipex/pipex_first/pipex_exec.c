#include "pipex.h"

void	pipex_exec(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		if(pipe(pipex->fd[i++]) == -1)
			free_all(pipex);
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->pid = fork();
		if (pipex->pid == -1)
			free_all(pipex);
		else if (pipex->pid == 0)
		{
			if (i == 0)
				pipex_ch1(pipex, i);
			if (i < pipex->cmd_count)
				pipex_ch2(pipex, i);
		}
		i++;
	}
}

void	pipex_ch1(t_obj *pipex, int i)
{
	close(pipex->fd[i][0]);
	dup2(pipex->infile_fd, 0);
	dup2(pipex->fd[i][1], 1);

	int		idx;
	char	*str;

	idx = 0;
	while (pipex->env_path[idx] != 0)
	{
		str = ft_strjoin(pipex->env_path[idx], pipex->cmd_path[i][0]);
		if (str == 0)
			free_all (pipex);
		if (access(str, F_OK) == -1)
			free(str);
		else
		{
			if (execve(str, pipex->cmd_path[i], NULL) == -1)
			{
				free(str);
				free_all (pipex);
				exit(1);
			}
		}
		idx++;
	}
	write(2, "error_check10 : lastpoint_error\n", 33);
	exit(1);
}

void	pipex_ch2(t_obj *pipex, int i)
{
	int		idx;
	char	*str;

	idx = 0;
	close(pipex->fd[i - 1][1]);
	close(pipex->fd[i][0]);
	dup2(pipex->fd[i - 1][0], 0);
	if (i < pipex->cmd_count - 1)
		dup2(pipex->fd[i][1], 1);
	else
		dup2(pipex->outfile_fd, 1);

	while (pipex->env_path[idx] != 0)
	{
		str = ft_strjoin(pipex->env_path[idx], pipex->cmd_path[i][0]);
		if (str == 0)
			free_all (pipex);
		if (access(str, F_OK) == -1)
			free(str);
		else
		{
			if (execve(str, pipex->cmd_path[i], NULL) == -1)
			{
				free(str);
				free_all (pipex);
				exit(1);
			}
		}
		idx++;
	}
	write(2, "error_check10 : lastpoint_error\n", 33);
	exit(1);
}
