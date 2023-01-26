#include "../minishell.h"
#include "../libft/libft.h"

int	unset(char **str, t_refer_env *refer_env)
{
	int	i;
	
	while (str[i] != NULL)
	{
		check_unset(str[i], refer_env->envp);
	}
}

void	check_unset(char *str, t_envp_list *envp)
{
	int	len;
	t_envp_list	*memo;
	t_envp_list	*free_memo;

	memo = envp;
	len = ft_strlen(str);
	if (strncmp(str, memo->key, len) == 0)
	{
		if(memo->key[len] == 0)
		{
			free_memo = memo;
			memo = memo->next;
			free(free_memo->key);
			free(free_memo->value);
			free(free_memo);
		}

	}

}