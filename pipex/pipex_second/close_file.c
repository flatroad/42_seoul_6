#include "pipex.h"

void	close_file(t_obj *pipex)
{
	close(pipex->infile_fd);
	close(pipex->outfile_fd);
	if (pipex->check_doc == 1)
		rm_temp(pipex);
}

void	rm_temp(t_obj *pipex)
{
	char	*rm[] = {"rm", "./temp", NULL};

	pipex->pid = fork();
	if (pipex->pid == -1)
		return ;
	if (pipex->pid == 0)
	{
		if (execve("/bin/rm", rm, 0) == -1)
		{
			write(2, "execve Fail", 11);
			exit(1);
		}
	}
	else
		wait(NULL);
}
