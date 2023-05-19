#include "../minishell.h"
#include "../libft/libft.h"

int	unset(char **str, t_refer_env *refer_env)
{
	int	i;
	
	i = 0;
	while (str[i] != NULL)
	{
		check_unset(str[i], refer_env);
		i++;
	}
	return (0);
}

void	check_unset(char *str, t_refer_env *refer_env)
{
	t_envp_list	*memo;
	t_envp_list	*before_memo;

	memo = refer_env->envp;
	before_memo = NULL;
	if (str == NULL)
		return ;
	while (memo != NULL)
	{
		if (same_check_unset(memo->key, str) == 0)
			delete_str_unset(refer_env, memo, before_memo);
		before_memo = memo;
		memo = memo->next;
	}

}

int	same_check_unset(char *s1, char *s2)
{
	int	len;

	len = ft_strlen(s1);
	if (len != ft_strlen(s2))
		return (1);
	if (strncmp(s1, s2, len) != 0)
		return (1);
	return (0);
}

void	delete_str_unset(t_refer_env *refer_env, t_envp_list *memo, \
t_envp_list *before_memo)
{
	if (before_memo == NULL)
	{
		free(memo->key);
		free(memo->value);
		refer_env->envp = memo->next;
		free(memo);
	}
	else
	{
		free(memo->key);
		free(memo->value);
		before_memo->next = memo->next;
		free(memo);
	}
}
