#include "../../includes/minishell.h"

void	exec_st(t_prompt *exec, t_ref_env *refer_env)
{
	t_station	*stt;

	signal(SIGINT, sig_exec);
	signal(SIGQUIT, sig_exec);
	stt = trans_stt(exec, refer_env);
	if (stt == NULL)
		execst_error_handle(0);
	if (find_path(stt->fok, stt) == 1)
		execst_error_handle(1);
	if (stt->fok->next == NULL)
		single_cmd(stt);
	else
		multi_cmd(stt);
	exec_free(stt);
}
