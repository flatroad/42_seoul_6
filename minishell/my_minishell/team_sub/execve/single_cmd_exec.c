#include "../minishell.h"
#include "../libft/libft.h"

extern int status;

void	single_fork(t_station *stt, char *path, char **cmd)
{
	if (set_dup(stt) != 0)
		sglcmd_error_handle(4, stt->fok);
	execve(path, cmd, NULL);
	sglcmd_error_handle(5, stt->fok);
	status = 1;
}
