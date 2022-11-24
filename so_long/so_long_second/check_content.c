/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:18:46 by sounchoi          #+#    #+#             */
/*   Updated: 2022/11/25 02:45:45 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_content(t_gm_obj *obj, t_err_c err_c)
{
	check_wall(obj, err_c);
	check_obj_num(obj, err_c);
	check_content_error(obj, err_c);
}

void	check_wall(t_gm_obj *obj, t_err_c err_c)
{
	int	i;

	i = 0;
	obj->x_max--;
	while (i < obj->x_max)
	{
		if (obj->map[0][i] != '1')
			error_handle_content(1, err_c);
		if (obj->map[obj->y_max][i] != '1')
			error_handle_content(1, err_c);
		i++;
	}
	i = 0;
	while (i <= obj->y_max)
	{
		if (obj->map[i][0] != '1')
			error_handle_content(1, err_c);
		if (obj->map[i][obj->x_max - 1] != '1')
			error_handle_content(1, err_c);
		i++;
	}
}

void	check_obj_num(t_gm_obj *obj, t_err_c err_c)
{
	int	i;
	int	j;

	i = 0;
	while (obj->map[i] != NULL)
	{
		j = 0;
		while (j != obj->x_max && obj->map[i][j] != 0)
		{
			calc_num(obj, obj->map[i][j], err_c);
			j++;
		}
		i++;
	}
}

void	calc_num(t_gm_obj *obj, char c, t_err_c err_c)
{
	if (ft_charcmp(c, 'C') == 0)
		obj->collection++;
	else if (ft_charcmp(c, 'E') == 0)
		obj->way_out++;
	else if (ft_charcmp(c, 'P') == 0)
		obj->way_in++;
	else if (ft_charcmp(c, '0') == 0)
		obj->free_zone++;
	else if (ft_charcmp(c, '1') == 0)
		obj->wall++;
	else if (ft_charcmp(c, 'F') == 0)
		obj->foe++;
	else
	{
		printf("c의 값은 : %d\n", c);
		error_handle_content(7, err_c);
	}
}

void	check_content_error(t_gm_obj *obj, t_err_c err_c)
{
	if (obj->collection < 1)
		error_handle_content(2, err_c);
	else if (obj->way_in < 1)
		error_handle_content(3, err_c);
	else if (obj->way_in > 1)
		error_handle_content(4, err_c);
	else if (obj->way_out < 1)
		error_handle_content(5, err_c);
	else if (obj->way_out > 1)
		error_handle_content(6, err_c);
	else
		return ;
}
