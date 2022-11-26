/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_visit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:21:08 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 03:03:46 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	possible_visit(t_obj_p *obj_p, int **visit, t_err_q err_q)
{
	check_posible_out(obj_p, visit, err_q);
	check_posible_collection(obj_p->col_list, visit, err_q);
}

void	check_posible_out(t_obj_p *obj_p, int **visit, t_err_q err_q)
{
	if (visit[obj_p->way_out[0]][obj_p->way_out[1]] != 1)
		error_handle_queue(3, err_q);
}

void	check_posible_collection(t_queue *que, int **visit, t_err_q err_q)
{
	while (que->first != NULL)
	{
		if (visit[que->first->x_y[0]][que->first->x_y[1]] != 1)
			error_handle_queue(4, err_q);
		pop_queue(que);
	}
	que->last = NULL;
	free(que);
	que = 0;
}
