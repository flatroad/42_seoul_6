/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:31 by sounchoi          #+#    #+#             */
/*   Updated: 2022/10/11 23:37:31 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	envp_path(char **envp, t_obj *pipex)
{
	char	**envp_path;

	while (strncmp("PATH=", *envp, 5) != 0)
		envp++;
	*envp = *envp + 5;
	envp_path = ft_split(*envp, ':');
	if (envp_path == NULL)
	{
		close_file(pipex);
		perror("error_check5 ");
		free(pipex);
		pipex = NULL;
		exit(1);
	}
	pipex->env_path = envp_path;
}
