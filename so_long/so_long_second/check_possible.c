/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_possible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:16:49 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 02:57:00 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_possible(t_gm_obj *obj, t_err_q err_q)
{
	t_obj_p	*obj_p;
	int		**visit;

	obj_p = init_obj_position(1, err_q);
	check_position(obj, obj_p, err_q);
	visit = ft_mk_multi_arr(obj->y_max + 1, obj->x_max);
	if (visit == NULL)
		error_handle_queue(2, err_q);
	pull_visit(obj->map, obj_p, visit, err_q);
	possible_visit(obj_p, visit, err_q);
	free_visit(visit, obj->y_max + 1);
	free(obj_p);
	obj_p = NULL;
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
			memo_position(obj->map[i][j], obj_p, err_q);
			j++;
		}
		i++;
	}
}

void	memo_position(char c, t_obj_p *obj_p, t_err_q err_q)
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

int	**ft_mk_multi_arr(int a, int b)
{
	int	i;
	int	j;
	int	**arr;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * a);
	if (arr == NULL)
		return (NULL);
	while (i < a)
	{
		arr[i] = (int *)malloc(sizeof(int) * b);
		if (arr[i] == NULL)
			return (NULL);
		i++;
	}
	pull_arr_zore(arr, a, b);
	return (arr);
}

void	pull_arr_zore(int **arr, int a, int b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < a)
	{
		j = 0;
		while (j < b)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}
