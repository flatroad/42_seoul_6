#include "../../includes/minishell.h"

t_station	*trans_stt(t_prompt *exec_ptr, t_refer_env *refer_env)
{
	t_station	*stt;
	t_list		*memo;

	stt = (t_station *)malloc(sizeof(t_station) * 1);
	if (stt == NULL)
		return (NULL);
	stt->env_list = refer_env->envp;
	stt->path_list = refer_env->path;
	memo = exec_ptr->cmds;
	stt = make_fok(memo, stt);
	if (stt == NULL)
		return (NULL);
	return (stt);
}

t_station	*make_fok(t_list *memo, t_station *stt)
{
	t_fork	*fok;

	fok = NULL;
	if (memo != NULL)
	{
		fok = add_fork((t_mini *)memo->content);
		if (fok == NULL)
			return (NULL);
		memo = memo->next;
	}
	stt->fok = fok;
	while (memo != NULL)
	{
		fok->next = add_fork((t_mini *)memo->content);
		if (fok->next == NULL)
			return (free_fork(stt));
		fok = fok->next;
		memo = memo->next;
	}
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
	return (NULL);
}

t_fork	*add_fork(t_mini *mini)
{
	t_fork	*fok;

	fok = (t_fork *)malloc(sizeof(t_fork) * 1);
	if (fok == NULL)
		return (NULL);
	fok->full_cmd = mini->full_cmd;
	fok->full_path = mini->full_path;
	fok->infile = mini->infile;
	fok->outfile = mini->outfile;
	fok->check = 0;
	if (fok->infile < 0 || fok->outfile < 0)
		fok->check = 4;
	fok->next = NULL;
	return (fok);
}
