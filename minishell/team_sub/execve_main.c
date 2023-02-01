#include "minishell.h"
#include "./libft/libft.h"

void	exec_st(t_refer_env *refer_env)
{
	t_station	*stt;

	// stt = trans_stt(exec);
	// if(find_path(stt->fok, stt) == 1)
	// 	return (0);
	stt = test_tran(refer_env);
	if (stt == NULL)
		return ;
	if (stt->fok->next == NULL)
		single_cmd(stt);
	// else
	// 	muti_cmd(stt);
}

t_station *test_tran(t_refer_env *refer_env)
{
	t_station *stt;
	char	**str;

	str = (char **)malloc(sizeof(char *) * 5);
	str[0] = "zzzz";
	str[1] = NULL;
	str[2] = NULL;
	str[3] = "sdf =123";
	str[4] = NULL;
	stt = (t_station *)malloc(sizeof(t_station) * 1);
	stt->env_list = refer_env->envp;
	stt->path_list = refer_env->path;
	stt->fok = (t_fork *)malloc(sizeof(t_fork) * 1);
	stt->fok->full_cmd = str;
	stt->fok->full_path = "./zzzz";
	stt->fok->infile = open("abc", O_RDONLY, 0644);
	stt->fok->outfile = 1;
	stt->fok->next = NULL;
	stt->pid = 0;

	return (stt);
}
