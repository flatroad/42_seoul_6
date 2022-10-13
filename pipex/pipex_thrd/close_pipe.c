#include "pipex.h"

void	close_pipe(t_obj *pipex, int max_i)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < max_i)
	{
		while(j < 2)
		{
			if (close(pipex->fd[i][j]) == -1)
			{
				perror("pipe is not close... ");
			}
			j++;
		}
		i++;
		j = 0;
	}
}
