#include "so_long.h"

void	check_content(t_gm_obj *obj)
{
	t_error_sb	errors;
	t_queue		col_que;
	t_queue		bfs;
	int			**visit;

	init_queue(&col_que);
	init_queue(&bfs);
	init_error_messege_sb(&errors);
	check_wall(obj, errors);
	check_obj_num(obj, errors, &col_que);
	visit = ft_mk_multi_arr(obj->y_max, obj->x_max);
	check_obj_coordinate(obj, errors);
	
}

void	check_wall(t_gm_obj *obj, t_error_sb errors)
{
	obj->x_max--;
	int	i = 0;
	while (i < obj->x_max)
	{
		if (obj->map[0][i] != '1')
			error_handle_sb(8, errors);
		if (obj->map[obj->y_max][i] != '1')
			error_handle_sb(8, errors);
		i++;
	}
	i = 0;
	while (i <= obj->y_max)
	{
		if (obj->map[i][0] != '1')
			error_handle_sb(8, errors);
		if (obj->map[i][obj->x_max - 1] != '1')
			error_handle_sb(8, errors);
		i++;
	}
}

void	check_obj_num(t_gm_obj *obj, t_error_sb errors, t_queue *col_que)
{
	int	i;
	int	j;

	i = 0;
	while (obj->map[i] != NULL)
	{
		j = 0;
		while (obj->map[i][j] != 0)
		{
			mk_col_que(obj, col_que, i, j);
		}

		i++;
	}
	if (obj->collection < 1)
		error_handle_sb(9, errors);
	if (obj->way_in != 1)
		error_handle_sb(10, errors);
	if (obj->way_out != 1)
		error_handle_sb(11, errors);
}

void	mk_col_que(t_gm_obj *obj, t_queue *col_que, int i, int j)
{
	t_error_que errors;

	init_error_que(&errors);
	if (ft_charcmp(obj->map[i][j], 'C') == 0)
	{
		obj->collection++;
		push_queue(col_que, errors, i, j);
	}
	if (ft_charcmp(obj->map[i][j], 'E') == 0)
		obj->way_out++;
	if (ft_charcmp(obj->map[i][j], 'P') == 0)
		obj->way_in++;
}
