#include "so_long.h"

void	check_possible(t_gm_obj *obj, t_err_q err_q)
{
	t_obj_p	*obj_p;

	obj_p = init_obj_position(err_q);
	check_position(obj, obj_p, err_q);
	while (obj_p->col_list->first != NULL)
	{
		printf("ssc %d, %d\n", obj_p->col_list->first->x_y[0], obj_p->col_list->first->x_y[1]);
		obj_p->col_list->first = obj_p->col_list->first->next;
	}
}

void	check_position(t_gm_obj *obj, t_obj_p *obj_p, t_err_q err_q)
{
	int	i;
	int	j;

	i = 0;
	while (obj->map[i] != NULL)
	{
		j = 0;
		while (obj->map[i][j] != 0)
		{
			obj_p->col = i;
			obj_p->row = j;
			calc_position(obj->map[i][j], obj_p, err_q);
			j++;
		}
		i++;
	}
}

void	calc_position(char c, t_obj_p *obj_p, t_err_q err_q)
{
	if (ft_charcmp(c, 'C') == 0)
		push_queue(obj_p->col_list, err_q, obj_p->col, obj_p->row);
	else if (ft_charcmp(c, 'P') == 0)
	{
		obj_p->way_in[0] = obj_p->col;
		obj_p->way_in[1] = obj_p->row;
	}
	else if (ft_charcmp(c, 'E') == 0)
	{
		obj_p->way_out[0] = obj_p->col;
		obj_p->way_out[1] = obj_p->row;
	}
	else
		return ;
}