#include "../../minishell.h"
#include "../../libft/libft.h"

t_envp_list	*is_pair(char *str, int	i)
{
	t_envp_list	*exp;

	exp = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (exp == NULL)
		return (NULL);
	if (make_key(&exp->key, str, i) == 1)
	{
		free(exp);
		return (NULL);
	}
	if (make_value(&exp->value, str, i) == 1)
	{
		free(exp->key);
		free(exp);
		return (NULL);
	}
	exp->next = NULL;
	return (exp);
}

t_envp_list	*is_single(char	*str)
{
	t_envp_list	*exp;

	exp = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (exp == NULL)
		return (NULL);
	exp->key = ft_strdup(str);
	if (exp->key == NULL)
	{
		free(exp);
		return (NULL);
	}
	exp->value = NULL;
	exp->next = NULL;
	return (exp);
}

int	make_key(char **key, char *str, int i)
{
	if (i == 0)
		*key = NULL;
	else
	{
		*key = ft_substr(str, 0, i);
		if (*key == NULL)
			return (1);
	}
	return (0);
}

int	make_value(char **value, char *str, int i)
{
	if (strlen(str + i + 1) == 0)
	{
		*value = malloc(sizeof(char) * 1);
		if (*value == NULL)
			return (1);
		*value[0] = 0;
	}
	else
	{
		*value = ft_substr(str, i + 1, strlen(str + i + 1));
		if (*value == NULL)
			return (1);
	}
	return (0);
}
