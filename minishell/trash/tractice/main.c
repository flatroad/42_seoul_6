#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

int	minishell(int argc, char **envp);

int main(int argc, char **argv, char **envp)
{
	if (argc != 1)
	{
		write(2, "you worng minishell start\n", 27);
		return (1);
	}
	if (minishell(argc, envp) != 1)
		return (1);
	return (0);
}

int	minishell(int argc, char **envp)
{
	char	*str;
	
	while (1)
	{
		str = readline("minishell > ");
		if (str != NULL)
			printf("%s\n", str);
		else
			printf("exit");
		add_history(str);
		free(str);
	}
	return (0);
}
