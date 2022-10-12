#include "pipex.h"

void	free_all(t_obj *pipex)
{
	perror("error_check10 ");
	free_pipe(pipex, pipex->cmd_count);
	free_cmd_all(pipex);
	free_envp(pipex);
	close_file(pipex);
	free(pipex);
	pipex = NULL;
	exit(1);
}
