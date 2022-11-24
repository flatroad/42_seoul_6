/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:15:31 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/24 18:07:23 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_object(t_gm_obj *obj)
{
	obj->fd = -1;
	obj->map = NULL;
	obj->wall = 0;
	obj->foe = 0;
	obj->player = 0;
	obj->collection = 0;
	obj->way_in = 0;
	obj->way_out = 0;
	obj->free_zone = 0;
	obj->x_max = 0;
	obj->y_max = 0;
}

t_queue	*init_queue(int i, t_err_q err_q)
{
	t_queue	*que;

	que = (t_queue *)malloc(sizeof(t_queue) * 1);
	if (que == NULL)
		error_handle_queue(i, err_q);
	que->first = NULL;
	que->count = 0;
	que->last = NULL;
	return (que);
}

t_obj_p	*init_obj_position(int i, t_err_q err_q)
{
	t_obj_p	*obj_p;

	obj_p = (t_obj_p *)malloc(sizeof(t_obj_p) * 1);
	if (obj_p == NULL)
		error_handle_queue(i, err_q);
	obj_p->col = 0;
	obj_p->row = 0;
	obj_p->way_in[0] = 0;
	obj_p->way_in[1] = 0;
	obj_p->way_out[0] = 0;
	obj_p->way_out[1] = 0;
	obj_p->col_list = init_queue(2, err_q);
	return (obj_p);
}
