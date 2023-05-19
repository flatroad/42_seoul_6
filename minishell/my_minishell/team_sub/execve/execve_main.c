#include "../minishell.h"
#include "../libft/libft.h"

void	exec_st(t_prompt *exec, t_refer_env *refer_env)
{
	t_station	*stt;
	t_fork		sd;

	// stt = trans_stt(exec, refer_env);
	stt = test_tran(refer_env);
	if (stt == NULL)
		execst_error_handle(0);
	if (find_path(stt->fok, stt) == 1)
		execst_error_handle(1);
	if (stt->fok->next == NULL)
		single_cmd(stt);
	else
		multi_cmd(stt);
}

t_station	*test_tran(t_refer_env *refer_env)
{
	t_station	*stt;
	t_fork		*memo;
	char		**str;
	char		**str2;
	char		**str3;
	int			i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * 3);
	str[0] = "cd";
	str[1] = "..";
	str[2] = NULL;
	str2 = (char **)malloc(sizeof(char *) * 3);
	str2[0] = "pwd";
	str2[1] = NULL;
	str2[2] = NULL;
	// str3 = (char **)malloc(sizeof(char *) * 3);
	// str3[0] = "wc";
	// str3[1] = "-l";
	// str3[2] = NULL;
	stt = (t_station *)malloc(sizeof(t_station) * 1);
	stt->env_list = refer_env->envp;
	stt->path_list = refer_env->path;
	stt->fok = (t_fork *)malloc(sizeof(t_fork) * 1);
	stt->fok->full_cmd = str;
	stt->fok->infile = 0;
	stt->fok->outfile = 1;
	stt->fok->next = (t_fork *)malloc(sizeof(t_fork) * 1);
	stt->fok->next->full_cmd = str2;
	stt->fok->next->infile = 3;
	stt->fok->next->outfile = 1;
	// stt->fok->next->next = (t_fork *)malloc(sizeof(t_fork) * 1);
	// stt->fok->next->next->full_cmd = str3;
	// stt->fok->next->next->infile = 4;
	// stt->fok->next->next->outfile = 1;
	// stt->fok->next->next->next = NULL;
	return (stt);
}
