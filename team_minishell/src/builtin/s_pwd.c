#include "../../includes/minishell.h"

void	s_pwd(int fd)
{
	char	path[1024];

	if (getcwd(path, 1024) == NULL)
	{
		ft_putstr_fd("Error, ", 2);
		ft_putendl_fd(strerror(errno), 2);
		g_status = 1;
	}
	ft_putendl_fd(path, fd);
	g_status = 0;
}
