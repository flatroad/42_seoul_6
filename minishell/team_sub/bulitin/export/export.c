#include "../../minishell.h"
#include "../../libft/libft.h"

int	export(char **exp_str, t_refer_env *refer_env)
{
	t_envp_list *exp;

	if (exp_str == NULL)
	{
		out_export(refer_env);
		return (0);
	}
	exp = make_exp(exp_str);
	if (exp == NULL)
	{
		write(2, "Error, export malloc fail..\n", 26);
		return (1);
	}
	if(output_exp(exp, refer_env) == 1)
	{
		write(2, "error, refer_env malloc fail..\n", 32);
		free_exp(exp);
		return (1);
	}
	free_exp(exp);
	return (0);
}
