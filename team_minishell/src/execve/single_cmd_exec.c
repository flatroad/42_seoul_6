#include "../../includes/minishell.h"

void	single_fork(t_station *stt, char *path, char **cmd, int pip[2])
{
	if (set_dup(stt, pip) != 0)
		sglcmd_error_handle(4, stt->fok);
	execve(path, cmd, NULL);
	sglcmd_error_handle(5, stt->fok);
	g_status = 1;
	exit(g_status);
}
