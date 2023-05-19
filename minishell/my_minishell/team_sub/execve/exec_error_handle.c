#include "../minishell.h"
#include "../libft/libft.h"

extern int status;

int	execst_error_handle(int cas)
{
	if (cas == 0)
		ft_putendl_fd("trans_stt malloc Fail...", 2);
	if (cas == 1)
		ft_putendl_fd("find_path malloc fail..", 2);
	status = 1;
	return (0);
}

int	mulcmd_error_handle(int cas, t_fork *fok)
{
	if (cas == 0)
		ft_putstr_fd("multi_cmd pipe fail: ", 2);
	else if (cas == 1)
		ft_putstr_fd("command not found: ", 2);
	else if (cas == 2)
		ft_putstr_fd("permission denied: ", 2);
	else if (cas == 3)
		ft_putstr_fd("fork fail: ", 2);
	else if (cas == 4)
		ft_putstr_fd("fork fail: ", 2);
	else if (cas == 5)
		ft_putstr_fd("execve is fail: ", 2);
	if (fok->full_cmd == NULL)
		ft_putstr_fd(fok->full_cmd[0], 2);
	ft_putchar_fd('\n', 2);
	status = 1;
	return (0);
}

int	sglcmd_error_handle(int cas, t_fork *fok)
{
	if (cas == 0)
		ft_putstr_fd("multi_cmd pipe fail: ", 2);
	else if (cas == 1)
		ft_putstr_fd("command not found: ", 2);
	else if (cas == 2)
		ft_putstr_fd("permission denied: ", 2);
	else if (cas == 3)
		ft_putstr_fd("fork fail: ", 2);
	else if (cas == 4)
		ft_putstr_fd("dup2 fail: ", 2);
	else if (cas == 5)
		ft_putstr_fd("execve is fail: ", 2);
	if (fok->full_cmd == NULL)
		ft_putstr_fd(fok->full_cmd[0], 2);
	ft_putchar_fd('\n', 2);
	status = 1;
	return (0);
}