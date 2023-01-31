#include "minishell.h"
#include "./libft/libft.h"

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		global_sig = 130;
		rl_replace_line("", 0);
		rl_on_new_line();
	}
	else if (sig == SIGQUIT)
	{
		global_sig = 131;
		write(2, "exit\n", 6);
	}
}
