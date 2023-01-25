#include "../minishell.h"
#include "../libft/libft.h"

int	env(t_refer_env *refer_env)
{
	t_envp_list	*memo;

	memo = refer_env->envp;
	while(memo != NULL)
	{
		ft_putstr_fd(memo->key, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(memo->value, 1);
		ft_putstr_fd("\n", 1);
		memo = memo->next;
	}
	return (1);
}
