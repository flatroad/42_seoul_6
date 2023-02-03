#include "../../includes/minishell.h"

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

void	sig_heredoc_rl(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 128 + SIGINT;
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGQUIT)
	{
		g_status = 128 + SIGQUIT;
		ft_putstr_fd("Quit: \n", STDOUT_FILENO);
	}
}

void	sig_exec(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 128 + SIGINT;
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	if (sig == SIGQUIT)
	{
		g_status = 128 + SIGQUIT;
		ft_putstr_fd("Quit: \n", STDOUT_FILENO);
	}
}
