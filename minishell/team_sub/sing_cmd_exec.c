#include "minishell.h"
#include "./libft/libft.h"

int	single_fork(t_station *stt, char *path, char **cmd, int *pip)
{
	set_single_pipe(stt, pip);
	if (set_dup(stt) != 0)
		return (1);
	execve(path, cmd, NULL);
	return (error_fork(strerror(errno), stt));
}

int	set_single_pipe(stt, pip)
{
	if ()
}