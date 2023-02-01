#include "../../minishell.h"
#include "../../libft/libft.h"

int	export(char **exp_str, t_envp_list *envp)
{
	t_envp_list *exp;

	if (exp_str[1] == NULL)
	{
		out_export(envp);
		return (0);
	}
	exp = make_exp(exp_str);
	if (exp == NULL)
	{
		write(2, "Error, export malloc fail..\n", 26);
		return (1);
	}
	if(output_exp(exp, envp) == 1)
	{
		write(2, "error, envp malloc fail..\n", 32);
		free_exp(exp);
		return (1);
	}
	free_exp(exp);
	return (0);
}
