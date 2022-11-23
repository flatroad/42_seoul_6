#include "so_long.h"

void	calc_way_inout(t_gm_obj *obj, char **map, t_obj_p *obj_p, t_err_q err_q)
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
		calc_way_inout(que, count, obj_p->way_out, map);
			
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
	{
		visit[i][j] = 1;
		return (0);
	}
}

int		calc_way_inout(t_queue *que, int count, int *way_way, char **map)
{
	while(count--)
	{
		if(check_visit*
	}
}