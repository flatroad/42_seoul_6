#include "../includes/minishell.h"

extern int	g_status;

static void	mini_getpid(t_prompt *p)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_perror(FORKERR, NULL, 1);
		ft_free_matrix(&p->envp);
		exit(1);
	}
	if (!pid)
	{
		ft_free_matrix(&p->envp);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	p->pid = pid - 1;
}

static t_prompt	init_vars(t_prompt prompt, char *str, char **argv)
{
	char	*num;

	str = getcwd(NULL, 0);
	prompt.envp = ft_setenv("PWD", str, prompt.envp, 3);
	free(str);
	str = ft_getenv("SHLVL", prompt.envp, 5);
	if (!str || ft_atoi(str) <= 0)
		num = ft_strdup("1");
	else
		num = ft_itoa(ft_atoi(str) + 1);
	free(str);
	prompt.envp = ft_setenv("SHLVL", num, prompt.envp, 5);
	free(num);
	str = ft_getenv("PATH", prompt.envp, 4);
	if (!str)
		prompt.envp = ft_setenv("PATH", \
		"/usr/local/sbin:/usr/local/bin:/usr/bin:/bin", prompt.envp, 4);
	free(str);
	str = ft_getenv("_", prompt.envp, 1);
	if (!str)
		prompt.envp = ft_setenv("_", argv[0], prompt.envp, 1);
	free(str);
	return (prompt);
}

static t_prompt	init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;
	char		*str;

	str = NULL;
	prompt.cmds = NULL;
	prompt.envp = ft_dup_matrix(envp);
	g_status = 0;
	mini_getpid(&prompt);
	prompt = init_vars(prompt, str, argv);
	return (prompt);
}

int	main(int argc, char **argv, char **envp)
{
	char				*str;
	char				*out;
	t_prompt			prompt;
	t_refer_env			*refer_env;

	prompt = init_prompt(argv, envp);
	refer_env = make_refer_env(envp);
	int i = 0;
	while (prompt.envp[i])
	{
		printf("%s\n", prompt.envp[i++]);
	}
	while (argv && argc)
	{
		signal(SIGINT, sigint_set_readline);
		signal(SIGQUIT, SIG_IGN);
		str = get_prompt(prompt);
		if (str)
			out = readline(str);
		else
			out = readline("guest@minishell $ ");
		free(str);
		if (!check_args(out, &prompt, refer_env))
			break ;
	}
	exit(g_status);
}
