#include "../../includes/minishell.h"

extern int	g_status;

static char	**split_all(char **args, t_prompt *prompt, t_ref_env *refer_env)
{
	char	**subsplit;
	int		i;
	int		quotes[2];

	i = -1;
	while (args && args[++i])
	{
		prompt->i = -1;
		args[i] = expand_vars(args[i], refer_env, quotes, prompt);
		subsplit = ft_cmdsubsplit(args[i], "<|>");
		ft_matrix_replace_in(&args, subsplit, i);
		i += ft_matrixlen(subsplit) - 1;
		ft_free_matrix(&subsplit);
	}
	return (args);
}

static void	*parse_args(char **args, t_prompt *p, t_ref_env *refer_env)
{
	int	is_exit;
	int	i;

	is_exit = 0;
	p->cmds = fill_nodes(split_all(args, p, refer_env), -1);
	if (!p->cmds)
		return (p);
	i = ft_lstsize(p->cmds);
	exec_st(p, refer_env);
	while (i-- > 0)
		waitpid(-1, &g_status, 0);
	if (args && is_exit)
	{
		ft_lstclear(&p->cmds, free_content);
		return (NULL);
	}
	return (p);
}

void	*check_args(char *out, t_prompt *p, t_ref_env *refer_env)
{
	char	**arg;
	t_mini	*n;

	if (!out)
	{
		printf("exit\n");
		return (NULL);
	}
	if (out[0] != '\0')
		add_history(out);
	arg = ft_cmdtrim(out, " ");
	free(out);
	if (!arg)
		ft_perror(QUOTE, NULL, 1);
	if (!arg)
		return ("");
	p = parse_args(arg, p, refer_env);
	if (p && p->cmds)
		n = p->cmds->content;
	if (p && p->cmds && n && n->full_cmd && ft_lstsize(p->cmds) == 1)
		p->envp = ft_setenv("_", n->full_cmd[ft_matrixlen(n->full_cmd) - 1], \
			p->envp, 1);
	if (p && p->cmds)
		ft_lstclear(&p->cmds, free_content);
	return (p);
}
