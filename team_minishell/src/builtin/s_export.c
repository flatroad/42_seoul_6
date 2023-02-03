#include "../../includes/minishell.h"

extern int	g_status;

void	s_export(char **exp_str, t_envp_list *envp, int fd)
{
	t_envp_list	*exp;

	if (exp_str[1] == NULL)
	{
		s_out_export(envp, fd);
		g_status = 0;
		return ;
	}
	exp = s_make_exp(exp_str);
	if (exp == NULL)
	{
		write(fd, "Error, export malloc fail..\n", 26);
		g_status = 1;
	}
	if (s_output_exp(exp, envp) == 1)
	{
		write(fd, "error, envp malloc fail..\n", 32);
		s_free_exp(exp);
		g_status = 1;
	}
	s_free_exp(exp);
	g_status = 0;
}
