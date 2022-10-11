#include "pipex.h"

void	free_envp(t_obj *pipex)
{
	int	i;

	i = 0;
	while (pipex->env_path[i] != 0)
	{
		free(pipex->env_path[i]);
		pipex->env_path[i] = 0;
		i++;
	}
	free(pipex->env_path);
	pipex->env_path = 0;
}

void	free_cmd(t_obj *pipex)
{
	int	i;

	i = 0;
	while(pipex->cmd_path[i] != 0)
	{
		free(pipex->cmd_path[i]);
		pipex->cmd_path[i] = 0;
		i++;
	}
	free(pipex->cmd_path);
	pipex->cmd_path = 0;
}

void	free_cmd_all (t_obj *pipex)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pipex->cmd_path[i] != 0)
	{
		while (pipex->cmd_path[i][j] != 0)
		{
			free(pipex->cmd_path[i][j]);
			pipex->cmd_path[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
	free_cmd(pipex);
}
