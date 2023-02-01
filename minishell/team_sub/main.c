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
