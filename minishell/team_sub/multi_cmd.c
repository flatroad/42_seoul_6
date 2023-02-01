#include "minishell.h"
#include "./libft/libft.h"

int	multi_cmd(t_station *stt)
{
	t_fork	*obj;

	obj = stt->fok;
	while (obj == NULL)
	{
		start_multi_cmd(obj, stt);
		obj = obj->next;
	}
	free_fork(stt->fok);
	return (0);
}

int	start_multi_cmd(t_fork *fok, t_station *stt)
{
	int	pip[2];
	int	i;

	i = 0;
	if (pipe(pip) == -1)
		return (0);
	if (fok->check != 0)
		return (fok->check);
	if (fok->next == NULL)
		i = 1;
	start_multi_fork(fok, stt, pip, i);
}

int	start_multi_fork(t_fork *fok, t_station *stt, int *pip, int i)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		close(pip[0]);
		close(pip[1]);
		return (1);
	}
	else if (pid == 0)
		check_multi_case(fok, stt, pip, i);
	else
	{
		if (i == 1 && fok->next->infile != 0)
			fok->next->infile = pip[0];
		else
			close(pip[0]);
	}
	return (0);
}

int	check_multi_case(t_fork *fok, t_station *stt, int *pip, int i)
{
	int	cas;

	if (set_pipe(fok, pip, i) == 1)
		return (1);
	cas = check_bulitin(fok->full_cmd[0]);
	if (cas != 0)
		exec_multi_bul(fok, stt, cas);
	else
		exec_multi_cmd(fok, stt);
}

int	set_pipe(t_fork *fok, int *pip, int i)
{
	if (fok->infile != 0)
	{
		if (dup2(fok->infile, 0) == -1)
			return (1);
		close(fok->infile);
	}
	if (fok->outfile != 1)
	{
		if (dup2(fok->outfile, 1) == -1)
			return (1);
		close(fok->outfile);
	}
	if (i == 0)
	{
		if (dup2(pip[1], 1) == -1)
			return (1);
	}
	close(pip[1]);
	close(pip[0]);
	return (0);
}
