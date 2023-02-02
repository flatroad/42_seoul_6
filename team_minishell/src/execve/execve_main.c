#include "../../includes/minishell.h"

void	exec_st(t_prompt *exec, t_refer_env *refer_env)
{
	t_station	*stt;
	t_mini		*cmd;

	stt = trans_stt(exec, refer_env);
	while (stt->fok != NULL)
	{

		exit(0);
	}
	if (stt == NULL)
		execst_error_handle(0);
	if (find_path(stt->fok, stt) == 1)
		execst_error_handle(1);
	if (stt->fok->next == NULL)
		single_cmd(stt);
	else
		multi_cmd(stt);
}
