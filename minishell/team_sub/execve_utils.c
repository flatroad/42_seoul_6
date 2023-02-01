#include "minishell.h"
#include "./libft/libft.h"

int	check_bulitin(t_fork *fok)
{
	int		len;
	char	*str;

	str = fok->full_cmd[0];
	len = ft_strlen(str);
	if (strncmp(str, "echo", len) == 0)
		return (1);
	else if (strncmp(str, "cd", len) == 0)
		return (2);
	else if (strncmp(str, "export", len) == 0)
		return (3);
	else if (strncmp(str, "env", len) == 0)
		return (4);
	else if (strncmp(str, "pwd", len) == 0)
		return (5);
	else if (strncmp(str, "unset", len) == 0)
		return (6);
	else if (strncmp(str, "exit", len) == 0)
		return (7);
	else
		return (0);
}
