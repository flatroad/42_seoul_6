#include "pipex.h"

void	get_pipe(t_obj *pipex)
{
	make_pipe1(pipex);
	make_pipe2(pipex);
}

void	make_pipe1(t_obj *pipex)
{
	pipex->fd = (int **)malloc(sizeof(int *) * pipex->cmd_count);
	if (pipex->fd == NULL)
	{
		perror("error_check9 ");
		free_cmd_all(pipex);
		free(pipex);
		pipex = NULL;
		exit(1);
	}
}

void	make_pipe2(t_obj *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		pipex->fd[i] = (int *)malloc(sizeof(int) * 2);
		if (pipex->fd[i] == 0)
		{
			perror("error_check9 ");
			free_pipe(pipex, i);
			free_cmd_all(pipex);
			free_envp(pipex);
			free(pipex);
			pipex = NULL;
			exit(1);
		}
		i++;
	}
}
