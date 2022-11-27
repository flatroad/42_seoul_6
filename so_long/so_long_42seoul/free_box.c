/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 03:03:26 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/26 12:54:15 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_visit(int **visit, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		free(visit[i]);
		visit[i] = NULL;
		i++;
	}
	free(visit);
	visit = NULL;
}
