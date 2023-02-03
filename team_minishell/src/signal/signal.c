#include "../../includes/minishell.h"
#include <ioctl.h>

int	g_status;

void	sigint_set_readline(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_status = 130;
	}
}

void	sig_exec(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	if (sig == SIGQUIT)
	{
		g_status = 128 + SIGQUIT;
		ft_putstr_fd("Quit: \n", STDOUT_FILENO);
	}
}
