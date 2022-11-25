/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 07:27:53 by younkim           #+#    #+#             */
/*   Updated: 2022/07/07 10:54:05 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_length(t_map *info)
{
	int	i;
	int	tmp2;

	i = 0;
	while (info->map[i])
		i++;
	info->column = i - 1;
	if (i < 3)
		file_error("Error\nMap : Column under 3");
	i = 0;
	info->row = ft_strlen(info->map[i]) - 1;
	i++;
	while (info->map[i])
	{
		tmp2 = ft_strlen(info->map[i]) - 1;
		if (info->row != tmp2)
			file_error("Error\nMap : Not equal number of lines");
		i++;
	}
}

static void	check_wall_map(t_map *info)
{
	int	column;
	int	i;

	column = 0;
	info->row = ft_strlen(info->map[0]) - 1;
	if (info->row == info->column)
		file_error("Error\nMap : Not Rectangle");
	i = -1;
	while (++i <= info->column)
		if (info->map[i][0] != '1' || info->map[i][info->row] != '1')
			file_error("Error\nMap : left or right column not wall");
	i = -1;
	while (info->map[0][++i])
		if (info->map[0][i] != '1' || info->map[info->column][i] != '1')
			file_error("Error\nMap : top or bottom not wall");
}

static void	effectiveness_check(t_map *info, int out)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= info->column)
	{
		j = -1;
		while (++j <= info->row)
		{
			if (info->map[i][j] == 'P' && info->start_x == 0)
			{
				info->start_x = j;
				info->start_y = i;
			}
			else if (info->map[i][j] == 'C')
				info->c_cnt++;
			else if (info->map[i][j] == 'E')
				out++;
			else
				if (!(info->map[i][j] == '0' || info->map[i][j] == '1'))
					file_error("ERROR\nMap : not allowed characters");
		}
	}
	if (!(info->start_x && info->c_cnt && out))
		file_error("ERROR\nMap : Minimum requirements not met");
}

static void	effectiveness_map_check(t_map *info)
{
	int	out;

	out = 0;
	info->start_x = 0;
	info->c_cnt = 0;
	info->start_y = 0;
	effectiveness_check(info, out);
}

void	check_map(t_map *info)
{
	is_length(info);
	check_wall_map(info);
	effectiveness_map_check(info);
}
