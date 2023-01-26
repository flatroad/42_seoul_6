#include "minishell.h"
#include "./libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_refer_env *refer_env;
	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		return (1);
	}
	refer_env = make_refer_env(envp);
	if (refer_env == NULL)
		return (1);
	export(NULL, refer_env);
	return (0);
}
