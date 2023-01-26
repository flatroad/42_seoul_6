#include "../../minishell.h"
#include "../../libft/libft.h"

int	output_exp(t_envp_list *exp, t_refer_env *refer_env)
{
	t_envp_list *memo;

	memo = exp;
	while(memo != NULL)
	{
		if(error_check(memo) == 1)
		{
			memo = memo->next;
			continue ;
		}
		if(push_export(exp, refer_env) == 1)
			return (1);
		memo = memo->next;
	}
	return (0);
}

int	error_check(t_envp_list *exp)
{
	int	i;

	i = 0;
	if (exp->key == NULL || ft_isdigit(exp->key[i]) == 1)
	{
		error_pr(exp);
		return (1);
	}
	return (0);
}

int	push_export(t_envp_list *exp, t_refer_env *refer_env)
{
	t_envp_list *memo;
	int			i;

	memo = refer_env->envp;
	while (memo != NULL)
	{
		i = same_check(memo, exp);
		if (i == 0)
			return (0);
		else if (i == 1)
			memo = memo->next;
		else
			return (1);
	}
	memo->next = change_refer(exp);
	if (memo->next == NULL)
		return (1);
	return (0);
}

int	same_check(t_envp_list *memo, t_envp_list *exp)
{
	int		i;
	char	*sv;

	i = ft_strlen(memo->key);
	if (i != ft_strlen(exp->key))
		return (1);
	if (ft_strncmp(memo->key, exp->key, i) != 0)
		return (1);
	sv = ft_strdup(exp->value);
	if (sv == NULL)
		return (2);
	free(memo->value);
	memo->value = sv;
	return (0);
}

t_envp_list	*change_refer(t_envp_list *exp)
{
	t_envp_list	*envp;

	envp = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (envp == NULL)
		return (NULL);
	envp->key = ft_strdup(exp->key);
	if (envp->key == NULL)
	{
		free(envp);
		return (NULL);
	}
	envp->value = ft_strdup(exp->value);
	if (envp->value == NULL)
	{
		free(envp->key);
		free(envp);
		return (NULL);
	}
	envp->next = NULL;
	return (envp);
}
