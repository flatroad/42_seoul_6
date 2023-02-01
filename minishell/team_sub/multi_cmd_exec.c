#include "minishell.h"
#include "./libft/libft.h"

int	exec_multi_cmd(t_fork *fok, t_station *stt)
{
	execve(fok->full_path[0], fok->full_cmd, NULL);
	return (0);
}
