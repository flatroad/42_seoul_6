/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:03:26 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 03:03:35 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visit(int **visit, int a)
{
	int	i;

	i = 0;
	while (i < a)
	{
		free(visit[i]);
		visit[i] = NULL;
		i++;
	}
	free(visit);
	visit = NULL;
}
