#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		return (1);
	}
	minishell(envp);
	return (0);
}

void	minishell(char **envp)
{
	t_tool tool;

	tool.envp = mk_envp(envp);
	tool.path = mk_path(envp);

	start_mini(&tool);
}

void	start_mini(t_tool *tool)
{
	char	*str;

	str = readline("prompt > ");
	add_history(str);
}