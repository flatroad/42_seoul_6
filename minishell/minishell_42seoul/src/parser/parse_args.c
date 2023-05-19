/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:06:04 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/05 03:46:53 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	**str;
	char	**temp[2];
	char	check;
	int		i;

	str = split_all(args, p, refer_env);
	temp[1] = get_trimmed(str);
	check = check_rdhd_syntax(str);
	if (check == -1)
	{
		stop_fill(NULL, str, temp[1]);
		return (p);
	}
	p->cmds = fill_nodes(str, -1, temp);
	if (!p->cmds)
		return (p);
	i = ft_lstsize(p->cmds);
	exec_st(p, refer_env);
	while (i-- > 0)
		waitpid(-1, &g_status, 0);
	trim_status();
	return (p);
}

void	*check_args(char *out, t_prompt *p, t_ref_env *refer_env)
{
	char	**arg;

	signal(SIGINT, sig_exec);
	signal(SIGQUIT, SIG_IGN);
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
		ft_lstclear(&p->cmds, free_content);
	return (p);
}
