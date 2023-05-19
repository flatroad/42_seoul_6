#include "../minishell.h"
#include "../libft/libft.h"

extern int status;

void	exec_multi_cmd(t_fork *fok, t_station *stt)
{
	execve(&fok->full_path[0], fok->full_cmd, NULL);

	mulcmd_error_handle(5, fok);
	status = 1;
}
