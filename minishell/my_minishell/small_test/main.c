#include "minishell.h"
#include "./libft/libft.h"

int	main(int argc, char **argv, char **envp)
{
	t_refer_env *refer_env;
	t_bundle	*mini;
	t_exec		*exec;
	char	*str;

	if (argc != 1)
	{
		write(2, "ERROR\nAn incorrect execution\n", 30);
		exit(1);
	}
	refer_env = make_refer_env(envp);
	if (refer_env == NULL)
		exit(1);
	while (1)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, handle_signal);
		str = readline("minishell-$ ");
		ft_parser(str, refer_env, mini, exec);
		ft_execve(exec, refer_env);
		free_all(mini);
	}
	return (0);
}

void	ft_execve(t_exec *exec, t_refer_env *refer_env)
{
	t_exec	*exec_proxy;

	exec_proxy = exec;
	if (exec_proxy == NULL)
		return ;
	else if (exec_proxy->check != 0)
		error_handle_exec(exec);
	else
	{
		while (exec_proxy != NULL)
		{
			pipe(exec->fd);
			exec->infile = dup(0);
			exec->outfile = dup(1);
			exec_start(exec, refer_env);
			free_exec(exec_proxy);
			exec_proxy = exec_proxy->next;
		}
	}
}

void	exec_start(t_exec *exec, t_refer_env *refer_env)
{
	
}

int	check_bulitin(t_exec *exec)
{
	int		len;
	char	*str;

	str = exec->cmd[0];
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