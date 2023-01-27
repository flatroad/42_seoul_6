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
	char	**str;

	str = (char **)malloc(sizeof(char *) * 5);
	str[0] = "a=b";
	str[1] = "adfa=";
	str[2] = "a = b";
	str[3] = "=12312";
	str[4] = NULL;
	char	**s = (char **)malloc(sizeof(char *) * 3);
	s[0] = "a";
	s[1] = "adfa";
	s[2] = NULL;
	export(str, refer_env);
	unset(s, refer_env);
	export(NULL, refer_env);
	return (0);
}
