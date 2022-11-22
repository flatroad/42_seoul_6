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

void	init_queue(t_queue *que)
{
	que->first = NULL;
	que->count = 0;
	que->last = NULL;
}

void	init_obj_position(t_obj_p *obj_p)
{
	obj_p->way_in[0] = 0;
	obj_p->way_in[1] = 0;
	obj_p->way_out[0] = 0;
	obj_p->way_out[1] = 0;
	init_queue(obj_p->col_list);
	init_queue(obj_p->foe_list);
}