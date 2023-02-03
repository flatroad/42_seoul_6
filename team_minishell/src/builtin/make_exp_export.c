#include "../../includes/minishell.h"

t_envp_list	*make_exp(char **exp_str)
{
	int			i;
	t_envp_list	*exp;
	t_envp_list	*memo;

	i = 2;
	memo = check_exp_str(exp_str[1]);
	if (memo == NULL)
		return (NULL);
	exp = memo;
	while (exp_str[i] != NULL)
	{
		memo->next = check_exp_str(exp_str[i]);
		if (memo->next == NULL)
		{
			free_exp(exp);
			return (NULL);
		}
		memo = memo->next;
		i++;
	}
	return (exp);
}

t_envp_list	*check_exp_str(char *str)
{
	t_envp_list	*exp;

	if (str[0] == 0)
		exp = is_exp_null();
	else
		exp = not_exp_null(str);
	if (exp == NULL)
		return (NULL);
	return (exp);
}

t_envp_list	*is_exp_null(void)
{
	t_envp_list	*exp;

	exp = malloc(sizeof(t_envp_list) * 1);
	if (exp == NULL)
		return (NULL);
	exp->key = NULL;
	exp->value = NULL;
	exp->next = NULL;
	return (exp);
}

t_envp_list	*not_exp_null(char *str)
{
	int			i;
	t_envp_list	*exp;

	i = 0;
	while (str[i] != '=' && str[i] != 0)
		i++;
	if (str[i] == '=')
		exp = is_pair(str, i);
	else
		exp = is_single(str);
	if (exp == NULL)
		return (NULL);
	return (exp);
}
