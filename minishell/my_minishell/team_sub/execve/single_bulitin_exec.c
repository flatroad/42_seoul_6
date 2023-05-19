#include "../minishell.h"
#include "../libft/libft.h"

int	single_bulitin(t_station *stt, int check)
{
	if (check == 1)
		echo(stt->fok->full_cmd);
	else if (check == 2)
		cd(stt->fok->full_cmd[1], stt->env_list);
	else if (check == 3)
		export(stt->fok->full_cmd, stt->env_list);
	else if (check == 4)
		env(stt->env_list);
	else if (check == 5)
		pwd();
	else if (check == 6)
		unset(stt->fok->full_cmd, stt->env_list);
	else if (check == 7)
		exit(0);
	return (0);
}
