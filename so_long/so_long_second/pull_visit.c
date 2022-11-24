/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_visit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:15:00 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/24 17:15:01 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pull_visit(char **map, t_obj_p *obj_p, int **visit, t_err_q err_q)
{
	int		count;
	t_queue	*que;

	que = init_queue(2, err_q);
	push_queue (que, err_q, obj_p->way_in[0], obj_p->way_in[1]);
	while (que->first != NULL)
		exec_visit(que, err_q, visit, map);
	free(que);
	que = 0;
}

void	exec_visit(t_queue *que, t_err_q err_q, int **visit, char **map)
{
	int	count;

	count = que->count;
	while (count--)
	{
		if (check_visit(visit, map, que->first->x_y[0] + 1, que->first->x_y[1]))
			push_queue(que, err_q, que->first->x_y[0] + 1, que->first->x_y[1]);
		if (check_visit(visit, map, que->first->x_y[0] - 1, que->first->x_y[1]))
			push_queue(que, err_q, que->first->x_y[0] - 1, que->first->x_y[1]);
		if (check_visit(visit, map, que->first->x_y[0], que->first->x_y[1] + 1))
			push_queue(que, err_q, que->first->x_y[0], que->first->x_y[1] + 1);
		if (check_visit(visit, map, que->first->x_y[0], que->first->x_y[1] - 1))
			push_queue(que, err_q, que->first->x_y[0], que->first->x_y[1] - 1);
		pop_queue(que);
	}
}

int	check_visit(int **visit, char **map, int i, int j)
{
	if (visit[i][j] == 1)
		return (0);
	else if (map[i][j] == '1' || map[i][j] == 'F')
	{
		visit[i][j] = 1;
		return (0);
	}
	else
	{
		visit[i][j] = 1;
		return (1);
	}
}
