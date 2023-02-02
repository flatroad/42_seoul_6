#include "../../includes/minishell.h"

extern int g_status;

void	env(t_envp_list *envp)
{
	t_envp_list	*memo;

	memo = envp;
	while(memo != NULL)
	{
		if (memo->value != NULL)
		{
			ft_putstr_fd(memo->key, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(memo->value, 1);
		}
		memo = memo->next;
	}
	g_status = 0;
}
