#include "minishell.h"
#include "./libft/libft.h"

t_station	*trans_stt(t_prompt *exec_ptr, t_refer_env *refer_env)
{
	t_station	*stt;
	t_list		*memo;
	t_fork		*fokl;

	stt->env_list = refer_env->envp;
	stt->path_list = refer_env->path;
	memo = exec_ptr->cmds;
	while (memo != NULL)
	{
		fokl = add_fork((t_mini *)memo->content);
		if (fokl == NULL)
			return (free_fork(stt));
		if (stt->fok == NULL)
			stt->fok = fokl;
		fokl = fokl->next;
		memo = memo->next;
	}
	stt->pid = 0;
	return (stt);
}

t_station	*free_fork(t_station *stt)
{
	t_fork	*sv;

	while (stt->fok != NULL)
	{
		sv = stt->fok;
		stt->fok = stt->fok->next;
		free(sv);
	}
	free(stt);
	ft_putendl_fd("Error, fok malloc fail..", 2);
	return (NULL);
}

t_fork	*add_fork(t_mini *mini)
{
	t_fork	*fok;

	fok = (t_fork *)malloc(sizeof(fok) * 1);
	if (fok == NULL)
		return (NULL);
	fok->full_cmd = mini->full_cmd;
	fok->full_path = mini->full_path;
	fok->infile = mini->infile;
	fok->outfile = mini->outfile;
	fok->next = NULL;
	return (fok);
}
