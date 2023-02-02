#include "../../includes/minishell.h"

int	g_status;

void	sigint_set_readline(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_status = 127;
	}
}
