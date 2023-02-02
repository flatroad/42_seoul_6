#include "../../includes/minishell.h"

int	exec_multi_bul(t_fork *fok, t_station *stt, int cas)
{
	multi_bulitin(stt, fok, cas);

	return (0);
}

int	multi_bulitin(t_station *stt, t_fork *fok, int cas)
{
	if (cas == 1)
		echo(fok->full_cmd);
	else if (cas == 2)
		cd(fok->full_cmd[1], stt->env_list);
	else if (cas == 3)
		export(fok->full_cmd, stt->env_list);
	else if (cas == 4)
		env(stt->env_list);
	else if (cas == 5)
		pwd();
	else if (cas == 6)
		unset(fok->full_cmd, stt->env_list);
	else if (cas == 7)
		exit(0);
	return (0);
}
