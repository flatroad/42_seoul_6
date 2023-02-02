#include "../../includes/minishell.h"

void	exec_st(t_prompt *exec, t_refer_env *refer_env)
{
	t_station	*stt;
	int	i;

	i = 0;
	stt = trans_stt(exec, refer_env);
	if (stt == NULL)
		execst_error_handle(0);
	if (find_path(stt->fok, stt) == 1)
		execst_error_handle(1);
	if (stt->fok->next == NULL)
		single_cmd(stt);
	else
		multi_cmd(stt);
}
