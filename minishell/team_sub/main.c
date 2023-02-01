#include "minishell.h"
#include "./libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_refer_env *refer_env;
	// t_prompt	*exec;
	char		*str;

	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		exit(1);
	}
	refer_env = make_refer_env(envp);
	if (refer_env == NULL)
		exit(1);
	exec_st(refer_env);
	return (0);
}

void	exec_st(t_refer_env *refer_env)
{
	t_station	*stt;

	// stt = trans_stt(exec);
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

	str = (char **)malloc(sizeof(char *) * 2);
	str[0] = "ls";
	str[1] = NULL;
	stt = (t_station *)malloc(sizeof(t_station) * 1);
	stt->env_list = refer_env->envp;
	stt->path_list = refer_env->path;
	stt->fok = (t_fork *)malloc(sizeof(t_fork) * 1);
	stt->fok->full_cmd = str;
	stt->fok->full_path = "/bin/ls";
	stt->fok->infile = 0;
	stt->fok->outfile = 1;
	stt->fok->next = NULL;
	stt->pid = 0;

	return (stt);
}

int	check_bulitin(t_fork *fok)
{
	int		len;
	char	*str;

	str = fok->full_cmd[0];
	len = ft_strlen(str);
	if (strncmp(str, "echo", len) == 0)
		return (1);
	else if (strncmp(str, "cd", len) == 0)
		return (2);
	else if (strncmp(str, "export", len) == 0)
		return (3);
	else if (strncmp(str, "env", len) == 0)
		return (4);
	else if (strncmp(str, "pwd", len) == 0)
		return (5);
	else if (strncmp(str, "unset", len) == 0)
		return (6);
	else if (strncmp(str, "exit", len) == 0)
		return (7);
	else
		return (0);
}
