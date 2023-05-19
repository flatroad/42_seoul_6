/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 21:59:06 by sounchoi          #+#    #+#             */
/*   Updated: 2023/02/05 01:06:36 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_status;

char	*ft_get_env_key(char *str, int i, char *key, t_prompt *prompt)
{	
	if (!key && str[i] == '$')
		key = ft_itoa(prompt->pid);
	else if (!key && str[i] == '?')
	{
		key = ft_itoa(g_status);
	}
	return (key);
}

static char	*get_substr_var(char *str, int i, \
t_ref_env *ref_env, t_prompt *prompt)
{
	char	*ret;
	int		pos;
	char	*path;
	char	*key;

	pos = ft_strchars_i(&str[i], "|\"\'$?>< ") + (ft_strchr("$?", str[i]) != 0);
	if (pos == -1)
		pos = ft_strlen(str) - 1;
	ret = ft_substr(str, 0, i - 1);
	key = ft_getenv(&str[i], ref_env, ft_strchars_i(&str[i], "\"\'$|>< "));
	key = ft_get_env_key(str, i, key, prompt);
	path = ft_strjoin(ret, key);
	free(ret);
	ret = ft_strjoin(path, &str[i + pos]);
	free (key);
	free (path);
	free (str);
	return (ret);
}

char	*expand_vars(char *str, t_ref_env *refer_env, \
						int quotes[2], t_prompt *prompt)
{
	char	*t_str;

	quotes[0] = 0;
	quotes[1] = 0;
	while (str && str[++(prompt->i)])
	{
		quotes[0] = (quotes[0] + (!quotes[1] && str[prompt->i] == '\'')) % 2;
		quotes[1] = (quotes[1] + (!quotes[0] && str[prompt->i] == '\"')) % 2;
		if (!quotes[0] && str[prompt->i] == '$' && str[prompt->i + 1])
		{
			t_str = get_substr_var(str, ++prompt->i, refer_env, prompt);
			return (expand_vars(t_str, refer_env, quotes, prompt));
		}
	}
	return (str);
}
