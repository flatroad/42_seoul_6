#include "../../includes/minishell.h"

extern int	g_status;

void	s_env(t_envp_list *envp, int fd)
{
	t_envp_list	*memo;

	memo = envp;
	while (memo != NULL)
	{
		if (memo->value != NULL)
		{
			ft_putstr_fd(memo->key, fd);
			ft_putstr_fd("=", fd);
			ft_putendl_fd(memo->value, fd);
		}
		memo = memo->next;
	}
	g_status = 0;
}
