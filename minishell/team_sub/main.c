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

int	find_path(t_fork *fork, t_station *stt)
{
	t_fork	*memo;

	memo = fork;
	while (memo != NULL)
	{
		conf_path(memo->full_cmd[0], memo, stt->env_list);
		if (fork->check == 10)
			return (1);
		memo = memo->next;
	}
	return (0);
}

void	conf_path(char *str, t_fork *fork, t_path_list *path)
{
	if (check_bulitin(str) == 0)
		return ;
	if (first_check(str, fork) == 0)
		return ;
	if (second_check(str, fork, path) == 0)
		return ;
}

int	first_check(char *str, t_fork *fork)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, X_OK) == 0)
		{
			fork->check = 0;
			fork->full_path = strdup(str);
			if (fork->full_path == NULL)
				fork->check = 10;
			return (0);
		}
		fork->check = 2;
		return (0);
	}
	fork->check = 1;
	return (1);
}

int	second_check(char *check, t_fork *fork, t_path_list *path)
{
	char		*str;
	t_path_list	*memo;

	memo = path;
	while (memo != NULL)
	{
		str = ft_strjoin_three(memo->value, "/", check);
		if (str == NULL)
		{
			fork->check = 10;
			return (0);
		}
		if (first_check(str, fork) == 0)
		{
			free(str);
			return (0);
		}
		free(str);
		memo = memo->next;
	}
	return (1);
}

char	*ft_strjoin_three(char *str_f, char *str_s, char *str_t)
{
	char	*str;
	char	*str_final;

	str = ft_strjoin(str_f, str_s);
	if (str == NULL)
		return (NULL);
	str_final = ft_strjoin(str, str_t);
	if (str_final == NULL)
	{
		free(str);
		return (NULL);
	}
	return (str_final);
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
