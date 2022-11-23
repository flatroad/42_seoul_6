#include "so_long.h"

void	calc_way_inout(t_gm_obj *obj, char **map, t_obj_p *obj_p, t_err_q err_q)
{
	int		**visit;
	int		count;
	int		flag;
	t_queue	*que;

	visit = ft_mk_multi_arr(obj->y_max + 1, obj->x_max);
	que = init_queue(3, err_q);
	flag = 1;
	push_queue (que, err_q, obj_p->way_in[0], obj_p->way_in[1]);
	while (flag)
	{
		count = que->count;
		while (count--)
		{
			fide_out()
			calc_way_inout(que, , obj_p->way_out, map);
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
	{
		visit[i][j] = 1;
		return (0);
	}
	else
	{
		visit[i][j] == 1;
		return (1);
	}
}

int		calc_way_inout(t_queue *que, int *way_way, char **map)
{
	while(count--)
	{
		if(check_visit*
	}
}