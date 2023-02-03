#include "../../includes/minishell.h"

extern int	g_status;

void	pwd(void)
{
	char	path[1024];

	if (getcwd(path, 1024) == NULL)
	{
		ft_putstr_fd("Error, ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_status = 1;
	}
	ft_putendl_fd(path, 1);
	g_status = 0;
}
