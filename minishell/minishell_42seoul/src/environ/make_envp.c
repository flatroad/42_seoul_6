/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:05:42 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:05:42 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_envp_list	*make_envp(char **envp)
{
	t_envp_list	*start;
	t_envp_list	*memo;
	int			i;

	i = 0;
	memo = add_envp_list(envp[i]);
	if (memo == NULL)
		return (NULL);
	start = memo;
	i++;
	while (envp[i] != NULL)
	{
		memo->next = add_envp_list(envp[i]);
		if (memo->next == NULL)
		{
			free_envp(0, start);
			return (NULL);
		}
		memo = memo->next;
		i++;
	}
	return (start);
}

t_envp_list	*add_envp_list(char *str)
{
	int			i;
	t_envp_list	*add;

	i = 0;
	add = (t_envp_list *)malloc(sizeof(t_envp_list) * 1);
	if (add == NULL)
		return (NULL);
	while (str[i] != '=')
		i++;
	add->key = ft_substr(str, 0, i);
	if (add->key == NULL)
		return (NULL);
	if (ft_strlen(str + i + 1) == 0)
	{
		add->value = (char *)malloc(sizeof(char) * 1);
		add->value[0] = 0;
	}
	else
		add->value = ft_substr(str, i + 1, ft_strlen(str + i + 1));
	if (add->value == NULL)
		return (NULL);
	add->next = NULL;
	return (add);
}
