/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:05:35 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/04 00:01:06 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(char *var, t_ref_env *refer_env, int n)
{
	int			n2;
	t_envp_list	*list;
	char		*str;

	list = refer_env->envp;
	if (n < 0)
		n = ft_strlen(var);
	while (!ft_strchr(var, '=') && list != NULL)
	{
		n2 = ft_strlen(list->key);
		if (n > n2)
			n2 = n;
		if (!ft_strncmp(list->key, var, n2))
		{
			str = ft_strdup(list->value);
			if (str == NULL)
				ft_putendl_fd("parser env malloc fail..", 2);
			return (str);
		}
		list = list->next;
	}
	return (NULL);
}
