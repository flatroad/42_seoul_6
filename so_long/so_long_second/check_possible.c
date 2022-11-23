#include "so_long.h"

void	check_possible(t_gm_obj *obj, t_err_q err_q)
{
	t_obj_p	*obj_p;

	obj_p = init_obj_position(1, err_q);
	check_position(obj, obj_p, err_q);
	calc_possible(obj, obj->map, obj_p, err_q);
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

void	calc_possible(t_gm_obj *obj, char **map, t_obj_p *obj_p, t_err_q err_q)
{
	int		**visit;
	int		count;
	t_queue	*que;

	visit = ft_mk_multi_arr(obj->y_max + 1, obj->x_max);
	que = init_queue(3, err_q);
	push_queue (que, err_q, obj_p->way_in[0], obj_p->way_in[1]);
	while (1)
	{
		count = que->count;
		while (count--)
		{
			if (check_visit(visit, map, que->first->x_y[0] + 1, que->first->x_y[1]))
				push_queue (que, err_q, que->first->x_y[0] + 1, que->first->x_y[1]);
			if (check)
		}
	}
	
}

int		check_visit(int **visit, char **map, int i, int j)
{
	if (visit[i][j] == 1)
		return (0);
	else if (map[i][j] == '1' || map[i][j] =='F')
	{
		visit[i][j] = 1;
		return (0);
	}
	else if (map[i][j] == 'E')
		return ()
}