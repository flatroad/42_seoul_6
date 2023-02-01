#include "../minishell.h"
#include "../libft/libft.h"

int	unset(char **str, t_envp_list *envp)
{
	int	i;
	
	i = 0;
	while (str[i] != NULL)
	{
		check_unset(str[i], envp);
		i++;
	}
	return (0);
}

void	check_unset(char *str, t_envp_list *envp)
{
	t_envp_list	*memo;
	t_envp_list	*before_memo;

	memo = envp;
	before_memo = NULL;
	if (str == NULL)
		return ;
	while (memo != NULL)
	{
		if (same_check_unset(memo->key, str) == 0)
			delete_str_unset(&envp, memo, before_memo);
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

void	delete_str_unset(t_envp_list **envp, t_envp_list *memo, \
t_envp_list *before_memo)
{
	if (before_memo == NULL)
	{
		free(memo->key);
		free(memo->value);
		*envp = memo->next;
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
