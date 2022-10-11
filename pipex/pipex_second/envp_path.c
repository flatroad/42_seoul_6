#include "pipex.h"

void	envp_path(char **envp, t_obj *pipex)
{
	char	**envp_path;

	while (strncmp("PATH=", *envp, 5) != 0)
		envp++;
	*envp = *envp + 5;
	envp_path = ft_split(*envp, ':');
	if (envp_path == NULL)
	{
		close_file(pipex);
		perror("error_check5 ");
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	pipex->env_path = envp_path;
}
