#include "../../includes/minishell.h"

void	free_exp(t_envp_list *exp)
{
	t_envp_list	*memo;	

	while (exp != NULL)
	{
		if (exp->key != NULL)
			free(exp->key);
		if (exp->value != NULL)
			free(exp->value);
		memo = exp;
		exp = exp->next;
		free(memo);
	}
}

void	error_pr(t_envp_list *exp)
{
	write(2, "Error, ", 8);
	if (exp->key != NULL)
		write(2, exp->key, ft_strlen(exp->key));
	write(2, "=", 2);
	if (exp->value != NULL)
		write(2, exp->value, ft_strlen(exp->value));
	write(2, " not a valid identifier\n", 24);
}
