#include "minishell.h"
#include "./libft/libft.h"

int	single_cmd(t_station *stt)
{
	int	check;

	if (stt->fok->infile < 0 || stt->fok->outfile < 0)
		return (0);
	check = check_bulitin(stt->fok);
	if (check != 0)
		single_bulitin(stt, check);
	else
		exec_single_cmd(stt);
	return (0);
}

int	exec_single_cmd(t_station *stt)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (error_handle(strerror(errno), stt));
	else if (pid == 0)
		single_fork(stt, stt->fok->full_path, stt->fok->full_cmd);
	else
		
	return (0);
}

int	set_dup(t_station *stt)
{
	if (stt->fok.)
	if (dup2(stt->fok->infile, 0) == -1)
		return (error_fork(strerror(errno), stt));
	if (dup2(stt->fok->outfile, 1) == -1)
		return (error_fork(strerror(errno), stt));
	return (0);
}
