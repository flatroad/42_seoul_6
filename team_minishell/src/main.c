#include "../includes/minishell.h"

extern int	g_status;

int	main(int argc, char **argv, char **envp)
{
	char				*out;
	t_prompt			prompt;
	t_refer_env			*refer_env;

	if (argc != 1 || argv[1] != NULL)
	{
		write(2, "try again your minishell\n", 26);
		return (1);
	}
	refer_env = make_refer_env(envp);
	while (1)
	{
		signal(SIGINT, sigint_set_readline);
		signal(SIGQUIT, SIG_IGN);
		out = readline("jun_soun@minishell$ ");
		if (!check_args(out, &prompt, refer_env))
			break ;
	}
	exit(g_status);
}
