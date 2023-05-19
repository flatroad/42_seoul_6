/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_envp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsyun <junsyun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 23:05:40 by junsyun           #+#    #+#             */
/*   Updated: 2023/02/03 23:05:40 by junsyun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**check_envp(char **envp)
{
	while (strncmp("PATH=", *envp, 5) != 0 && envp != NULL)
		envp++;
	if (envp == NULL)
		return (NULL);
	else
	{
		*envp = *envp + 5;
		return (envp);
	}
}
