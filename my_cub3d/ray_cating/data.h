/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sounchoi <sounchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:04:51 by junlee2           #+#    #+#             */
/*   Updated: 2023/03/25 19:20:28 by sounchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

#include "minilibx_mms_20210621/mlx.h"

# define RED 0
# define GREEN 1
# define BLUE 2
# define G_W 640
# define G_H 480
# define IMG_W 64
# define IMG_H 64
# define E 0
# define W 1
# define S 2
# define N 3

//X11 interface
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53
# define KEY_LEFT	123
# define KEY_RIGHT	124
# define KEY_DOWN	125
# define KEY_UP		126

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17
//------------------------------

typedef int	t_rgb;

typedef struct s_map
{
	int		xsize;
	int		ysize;
	char	**map;
}	t_map;

typedef struct s_input
{
	char	*no_png;
	char	*so_png;
	char	*we_png;
	char	*ea_png;
	char	*floor;
	char	*ceiling;
	char	**map;
}	t_input;

typedef struct s_libx
{
	void	*mlx;
	void	*mlx_win;
	char	*win_name;
}	t_libx;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_texture
{
	t_image	img_box[6];
	t_image	*wall_n;
	t_image	*wall_s;
	t_image	*wall_e;
	t_image	*wall_w;
	t_rgb	floor;
	t_rgb	ceiling;
}	t_texture;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_detail_info
{
	double	ray_range;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	first_dist_x;
	double	first_dist_y;
	double	squ_per_dist_x;
	double	squ_per_dist_y;
	int		step_x;
	int		step_y;
	double	verti_wall_dist;
	int		hit;
	int		side;
	int		four_dir;
}	t_detail_info;

typedef	struct	s_other_draw
{
	int		draw_start;
	int		draw_end;
	double	draw_pos;
	int		get_img_x;
	int		get_img_y;
	int		draw_img_x;
	int		draw_img_y;
	double	step;
	int		color;
	int		away_dist;
	double	wall_x;
}	t_other_draw;



typedef struct s_data
{
	t_libx		*libx;
	t_input		*input;
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
	t_image		*screen;
}	t_data;

typedef struct s_map_obj
{
	int	player;
}	t_map_obj;

#endif