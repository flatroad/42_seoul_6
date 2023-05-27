/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_output_exp_export.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:05:22 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:05:22 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	s_output_exp(t_envp_list *exp, t_envp_list *envp)
{
	t_envp_list	*memo;

	memo = exp;
	while (memo != NULL)
	{
		if (s_error_check(memo->key) == 1)
		{
			error_pr(memo);
			memo = memo->next;
			continue ;
		}
		if (s_push_export(memo, envp) == 1)
			return (1);
		memo = memo->next;
	}
	return (0);
}

int	s_error_check(char *str)
{
	int	i;
	int	len;

	i = 1;
	if (str == NULL)
		return (1);
	len = ft_strlen(str);
	if (ft_isdigit(str[0]) == 1 || str[0] == ' ')
		return (1);
	while (i < len)
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	s_push_export(t_envp_list *exp, t_envp_list *envp)
{
	t_envp_list	*memo;
	int			i;

	memo = envp;
	while (memo != NULL)
	{
		i = s_same_check(memo, exp);
		if (i == 0)
			return (0);
		else if (i == 1)
		{
			if (memo->next == NULL)
				break ;
			memo = memo->next;
		}
		else
			return (1);
	}
	memo->next = s_change_refer(exp);
	if (memo->next == NULL)
		return (1);
	return (0);
}

int	s_same_check(t_envp_list *memo, t_envp_list *exp)
{
	int		i;
	char	*sv;

	i = ft_strlen(memo->key);
	if (i != (int)ft_strlen(exp->key))
		return (1);
	if (ft_strncmp(memo->key, exp->key, i) != 0)
		return (1);
	if (exp->value == NULL)
	{
		free(memo->value);
		memo->value = NULL;
		return (0);
	}
	else
	{
		sv = ft_strdup(exp->value);
		if (sv == NULL)
			return (2);
	}
	if (memo->value != NULL)
		free(memo->value);
	memo->value = sv;
	return (0);
}

t_envp_list	*s_change_refer(t_envp_list *exp)
{
	t_envp_list	*envp;

	envp = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (envp == NULL)
		return (NULL);
	envp->key = ft_strdup(exp->key);
	if (envp->key == NULL)
	{
		free(envp);
		return (NULL);
	}
	if (exp->value == NULL)
		envp->value = NULL;
	else
	{
		envp->value = ft_strdup(exp->value);
		if (envp->value == NULL)
		{
			free(envp->key);
			free(envp);
			return (NULL);
		}
	}
	envp->next = NULL;
	return (envp);
}