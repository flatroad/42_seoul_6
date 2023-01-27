#include "../minishell.h"
#include "../libft/libft.h"

int	pwd(void)
{
	char	path[1024];
	int		len;

	if (getcwd(path, 1024) == NULL) {

		write(2, "Error, ", 8);
		len = ft_strlen(strerror(errno));
		write(2, strerror(errno), len);
		write(2, "\n", 2);
		return (1);
	}
	ft_putendl_fd(path, 1);
	return (0);
}
