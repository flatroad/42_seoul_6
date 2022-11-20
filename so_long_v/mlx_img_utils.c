/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younkim <younkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:42:30 by younkim           #+#    #+#             */
/*   Updated: 2022/07/07 10:53:15 by younkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map(t_mlx *mlx, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->wall_img, x, y);
	else if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->zero_img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->collect_img, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->start_img, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->win_mlx, mlx->out_img, x, y);
}

static void	print_map_handle(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i <= mlx->info->column)
	{
		j = 0;
		while (j <= mlx->info->row)
		{
			print_map(mlx, mlx->info->map[i][j], j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	mlx_setting(t_mlx *mlx)
{
	int		width;
	int		height;

	mlx->mlx = mlx_init();
	mlx->win_mlx = mlx_new_window(mlx->mlx, \
		(mlx->info->row + 1) * TILE_SIZE, \
		(mlx->info->column + 1) * TILE_SIZE, "so_long");
	mlx->start_img = mlx_xpm_file_to_image(mlx->mlx, \
		"xpmfiles/dog.xpm", &width, &height);
	mlx->wall_img = mlx_xpm_file_to_image(mlx->mlx, \
		"xpmfiles/tree.xpm", &width, &height);
	mlx->zero_img = mlx_xpm_file_to_image(mlx->mlx, \
		"xpmfiles/land.xpm", &width, &height);
	mlx->collect_img = mlx_xpm_file_to_image(mlx->mlx, \
		"xpmfiles/food.xpm", &width, &height);
	mlx->out_img = mlx_xpm_file_to_image(mlx->mlx, \
		"xpmfiles/house.xpm", &width, &height);
	mlx->end_img = mlx_xpm_file_to_image(mlx->mlx, \
		"xpmfiles/end.xpm", &width, &height);
	print_map_handle(mlx);
}
