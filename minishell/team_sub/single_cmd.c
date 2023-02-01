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
	stt->pid = fork();
	if (stt->pid < 0)
		return (error_handle(strerror(errno), stt));
	else if (stt->pid == 0)
		single_fork(stt, stt->fok->full_path, stt->fok->full_cmd);
	return (0);
}

int	single_fork(t_station *stt, char *path, char **cmd)
{
	if (set_dup(stt) != 0)
		return (1);
	execve(path, cmd, NULL);
	return (error_fork(strerror(errno), stt));
}

int	single_bulitin(t_station *stt, int check)
{
	// if (check == 1)
	// 	echo(stt->fok->full_cmd);
	// else if (check == 2)
	// 	cd(stt->fok->full_cmd[1], stt->env_list);
	// else if (check == 3)
	// 	export(stt->fok->full_cmd, stt->env_list);
	// else if (check == 4)
	// 	env(stt->env_list);
	// else if (check == 5)
	// 	pwd();
	// else if (check == 6)
	// 	unset(stt->fok->full_cmd, stt->env_list);
	// else if (check == 7)
	// 	exit(0);
	return (0);
}

int	set_dup(t_station *stt)
{
	if (dup2(stt->fok->infile, 0) == -1)
		return (error_fork(strerror(errno), stt));
	if (dup2(stt->fok->outfile, 1) == -1)
		return (error_fork(strerror(errno), stt));
	return (0);
}
