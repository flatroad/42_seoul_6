#include "../minishell.h"
#include "../libft/libft.h"

int	single_cmd(t_station *stt)
{
	int	check;

	if (stt->fok->check != 0 && stt->fok->check != 9)
		return (sglcmd_error_handle(stt->fok->check, stt->fok));
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
		return (sglcmd_error_handle(3, stt->fok));
	else if (pid == 0)
		single_fork(stt, stt->fok->full_path, stt->fok->full_cmd);
	return (0);
}

int	set_dup(t_station *stt)
{
	if (stt->fok->infile != 0)
	{
		if (dup2(stt->fok->infile, 0) == -1)
			return (sglcmd_error_handle(4, stt->fok));
		close(stt->fok->infile);
	}
	if (stt->fok->outfile != 1)
	{
		if (dup2(stt->fok->outfile, 1) == -1)
			return (sglcmd_error_handle(4, stt->fok));
		close(stt->fok->outfile);
	}
	return (0);
}