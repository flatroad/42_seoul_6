#include "../../includes/minishell.h"

extern int	g_status;

void	exec_multi_cmd(t_fork *fok)
{
	execve(&fok->full_path[0], fok->full_cmd, NULL);
	mulcmd_error_handle(5, fok);
	g_status = 1;
	exit(g_status);
}
